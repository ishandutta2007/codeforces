#include<bits/stdc++.h>

using namespace std;

// https://qiita.com/drken/items/1b7e6e459c24a83bb7fd
template <class Abel> struct BIT {
    vector<Abel> dat;
    Abel UNITY_SUM = 0;                     // to be set

    /* [1, n] */
    BIT(int n) { init(n); }
    void init(int n) {
        dat.resize(n + 1);
        for (int i = 0; i < (int)dat.size(); ++i) dat[i] = UNITY_SUM;
    }

    /* a is 1-indexed */
    inline void add(int a, Abel x) {
        for (int i = a; i < (int)dat.size(); i += i & -i)
            dat[i] = dat[i] + x;
    }

    /* [1, a], a is 1-indexed */
    inline Abel sum(int a) {
        Abel res = UNITY_SUM;
        for (int i = a; i > 0; i -= i & -i)
            res = res + dat[i];
        return res;
    }

    /* [a, b), a and b are 1-indexed */
    inline Abel sum(int a, int b) {
        return sum(b - 1) - sum(a - 1);
    }

    /* k-th number (k is 0-indexed) */
    int get(long long k) {
        ++k;
        int res = 0;
        int N = 1; while (N < (int)dat.size()) N *= 2;
        for (int i = N / 2; i > 0; i /= 2) {
            if (res + i < (int)dat.size() && dat[res + i] < k) {
                k = k - dat[res + i];
                res = res + i;
            }
        }
        return res + 1;
    }
};

void merge(vector<int> &a,vector<int> &b){
  if(a.size()<b.size()){swap(a,b);}
  for(auto &nx : b){a.push_back(nx);}
  b.clear();
}

#define ulim 320000
using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,q;
  cin >> n >> q;
  vector<int> a(n);
  for(auto &nx : a){cin >> nx;}
  BIT<int> st(ulim);
  for(int i=1;i<ulim;i++){st.add(i,1);}
  vector<vector<int>> mem(ulim);
  vector<int> f(n,-1);
  for(int i=n-1;i>=0;i--){
    int cur=(i+1)-a[i];
    if(cur<0){continue;}
    else if(cur==0){
      f[i]=i;
      int tg=st.get(0);
      for(auto &nx : mem[tg]){f[nx]=i;}
      st.add(tg,-1);
    }
    else if(cur<=i){
      int mt=st.get(cur-1);
      int mf=st.get(cur);
      merge(mem[mt],mem[mf]);
      mem[mt].push_back(i);
      st.add(mf,-1);
    }
  }

  vector<vector<int>> awake(n);
  for(int i=0;i<n;i++){
    //cout << f[i] << ' ';
    if(f[i]>=0){awake[f[i]].push_back(i);}
  }//cout << '\n';

  vector<int> res(q);
  vector<vector<pi>> query(n);
  for(int i=0;i<q;i++){
    int x,y;
    cin >> x >> y;
    query[x].push_back({n-y,i});
  }

  BIT<int> bit(ulim);
  for(int i=n-1;i>=0;i--){
    for(auto &nx : awake[i]){bit.add(nx+1,1);}
    for(auto &nx : query[i]){
      res[nx.second]=bit.sum(i+1,nx.first+1);
    }
  }

  for(auto &nx : res){cout << nx << '\n';}
  return 0;
}