#include <stdio.h>
#include <bits/stdc++.h>

#define FOR(i, n)     for(int i = 0; i < (int)(n); ++i)
#define all(a) begin(a),end(a)

using namespace std;

//------------------------------------------------------------------------------

struct wavelet_tree {
  int lo=0, hi=0;
  wavelet_tree *l = 0, *r = 0;
  vector<int> b;

  wavelet_tree() = default;

  ~wavelet_tree(){
    if(l) delete l;
    if(r) delete r;
  }

  wavelet_tree(vector<int> &&A) : wavelet_tree(begin(A),end(A),*min_element(all(A)),*max_element(all(A))) { }

  template<typename IT>
  wavelet_tree(IT from, IT to, int lo_, int hi_) {
    lo=lo_; hi=hi_;
    int mi = lo + (hi-lo)/2;
    auto f = [&](int x) { return x <= mi; };
    b.reserve(distance(from,to)+1); b.push_back(0);
    for(auto it = from; it != to; ++it) b.push_back(b.back() + f(*it));
    auto mit = stable_partition(from,to,f);
    if(lo == hi || from == to) return;
    l = new wavelet_tree(from,mit,lo,mi);
    r = new wavelet_tree(mit,to,mi+1,hi);
  }

  /*
   * cnt(l,r,y) : number of occurences of y in A[l]..A[r]
   */
  int cnt(int l, int r, int y) {
    if(l>r) return 0;
    if(lo == hi) {
      if(lo == y) {
        return b[r+1]-b[l];
      }else{
        return 0;
      }
    }else{
      int mi = lo + (hi-lo)/2;
      if(y<=mi) {
        return this->l->cnt(b[l],b[r+1]-1,y);
      }else{
        return this->r->cnt(l-b[l],r-b[r+1],y);
      }
    }
  }

  void solve(int l, int r, int k, function<void(int)> f) {
    if(r-l+1 < k) return;
    if(lo == hi) {
      f(lo);
    }else{
      this->l->solve(b[l],b[r+1]-1,k,f);
      this->r->solve(l-b[l],r-b[r+1],k,f);
    }
  }
};

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,q; cin>>n>>q;
  vector<int> A(n);
  FOR(i,n) cin>>A[i];
  wavelet_tree wt(move(A));
  FOR(i,q) {
    int l,r,k;
    cin>>l>>r>>k;
    --l; --r;
    int x=-1;
    wt.solve(l,r,(r-l+1)/k+1,[&](int y) { if(x==-1||y<x) x=y; });
    cout << x << '\n';
  }
  return 0;
}