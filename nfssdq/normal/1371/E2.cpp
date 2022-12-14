#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<string>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<climits>
#include<complex>
using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        998244353ll
#define PI         acos(-1.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

int seg[800001][3], val[800001];
void build(int idx, int s, int e){
  if(s == e){
    seg[idx][0] = seg[idx][1] = seg[idx][2] = val[s];
    return;
  }
  int mid = (s + e) / 2;
  build(idx * 2 + 1, s, mid);
  build(idx * 2 + 2, mid + 1, e);
  seg[idx][0] = min(seg[idx * 2 + 1][0], seg[idx * 2 + 1][2] + seg[idx * 2 + 2][0]);
  seg[idx][1] = max(seg[idx * 2 + 1][1], seg[idx * 2 + 1][2] + seg[idx * 2 + 2][1]);
  seg[idx][2] = seg[idx * 2 + 1][2] + seg[idx * 2 + 2][2];
}
pair<pair<int,int>, int> query(int idx, int s, int e, int st, int ed, int x){
  if(s == st && e == ed){
    return mp( mp(x + seg[idx][0], x + seg[idx][1]), x + seg[idx][2]);
  }
  int mid = (s + e) / 2;
  if(ed <= mid) return query(idx * 2 + 1, s, mid, st, ed, x);
  else if(st > mid) return query(idx * 2 + 2, mid + 1, e, st, ed, x);
  else {
    pair<pair<int,int>,int> pl = query(idx * 2 + 1, s, mid, st, mid, x);
    pair<pair<int,int>,int> pr = query(idx * 2 + 2, mid + 1, e, mid + 1, ed, pl.yy);
    pr.xx.xx = min(pr.xx.xx, pl.xx.xx);
    pr.xx.yy = max(pr.xx.yy, pl.xx.yy);
    return pr;
  }
}

map<int,int> mm;
int ar[100001];
vector < int > res;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, pr; cin >> n >> pr;
  FOR(i, 1, n+1) cin >> ar[i];
  sort(ar + 1, ar + n + 1);
  FOR(i, 1, n+1) mm[ar[i]]++;
  
  int s = 0;
  for(int i = ar[n] - n; i <= ar[n]; i++){
    REP(j, mm[i]) val[++s] = 1;
    val[++s] = -1;
  }
  build(0, 1, s);

  int st = 0, t = 0;
  for(int i = 1; i <= n; i++) if(ar[n] - n > ar[i]) st++;
  for(int i = ar[n] - n; i <= ar[n]; i++){
    st += mm[i];
    if(st >= pr) break;
    t += mm[i] + 1;
    pair<pair<int,int>,int> p = query(0, 1, s, t, s, st);
    // cout << i << " " << p.xx.xx << " " << p.xx.yy << " " << p.yy << " " << st << endl;
    if(st >= pr || p.xx.xx < 0 || p.xx.yy >= pr) continue;
    res.pb(i);
  }

  cout << res.size() << endl;
  REP(i, res.size()) cout << res[i] << " ";
  cout << endl;
}