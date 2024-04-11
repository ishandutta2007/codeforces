    #include <iostream>
    #include <algorithm>
    #include <vector>
    #include <queue>
    #include <cstring>
    #include <cmath>
    #include <cstdlib>
    #include <cstdio>
    #include <unordered_map>
    using namespace std;
    typedef pair<int, int> pii;
    typedef pair<double, pii> pipii;
    typedef long long int ll;
    #define REP(i,x) for(int i=0;i<(int)(x);i++)
    #define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
    #define RREP(i,x) for(int i=(x-1);i>=0;i--)
    #define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();i++)
    #include <complex>
    #include <cmath>
    #define EPS 1.0e-10
    #define PI 3.1415926535897932384
    const ll MOD = 1000000007;
     
    typedef int SegT;
const int defvalue = 0;
class SegTree{
private:
  vector<SegT> val;
  int n;
public:
  SegTree(){
  }
  SegTree(int size){
    n=1;
    while(n<size)n<<=1;
    val=vector<SegT>(2*n, defvalue);
  }
  SegTree(const vector<SegT> &in){
    n=1;
    while(n<in.size())n<<=1;
    val=vector<SegT>(2*n, defvalue);
    for(int i=n-1 + in.size()-1;i>=0;i--){
      if(n-1 <= i) val[i] = in[i - (n-1)];
      else val[i] = __gcd(val[i*2+1],val[i*2+2]);
    }
  }
  //i  a 
  void update(int i,SegT a){
    i+=n-1;
    val[i]=a;
    while(i>0){
      i=(i-1)/2;
      val[i]=__gcd(val[i*2+1],val[i*2+2]);
    }
  }
  //[a, b) 
  SegT query(int a,int b,int k=0,int l=0,int r=-1){
    if(r==-1)r=n;
    if(r<=a||b<=l) return defvalue;
    if(a<=l&&r<=b){
      return val[k];
    }else{
      return __gcd(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2,r));
    }
  }
};

vector<pii> change;
SegTree seg;

void search(int s, int l, int r, int lv, int rv){
  // printf("search %d %d %d %d %d\n", s, l, r, lv, rv);
  if(r-l <= 1){
    if(rv != lv) change.push_back(pii(l, rv));
  }else{
    int mid = (l+r)/2;
    int ret = seg.query(s, mid);
    if(ret != lv) search(s, l, mid, lv, ret);
    if(ret != rv) search(s, mid, r, ret, rv);
  }
}
int N, M;
main(){
  scanf("%d", &N);
  vector<int> v(N);
  REP(i, N){
    scanf("%d", &v[i]);
  }
  scanf("%d", &M);
  vector<int>  Q(M);

  seg = SegTree(v);
  unordered_map<int, ll> ans;
  REP(i, M){
    int t;
    scanf("%d", &t);
    ans[t] = 0;
    Q[i] = t;
  }
  REP(i, N){
    if(i && v[i] == v[i-1]){
      change[0].first ++;
    }else{
      change.clear();
      change.push_back(pii(i, v[i]));
      int rv = seg.query(i, N);
      if(v[i] != rv) search(i, i+1, N+1, v[i], rv);
      change.push_back(pii(N, 0));
    }
    // REP(j, change.size()) printf("(%d, %d) ", change[j].first, change[j].second);
    // puts("");
    RREP(j, change.size()-1){
      auto ret = ans.find(change[j].second);
      if(ret != ans.end()) ret->second += change[j+1].first - change[j].first;
    }
  }
  FOR(it, Q) printf("%I64d\n", ans[*it]);
  // printf("%d\n", ans);
}