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

string S;

struct obj {
  int prefix, suffix, mx, last, first, sz;
  obj(int p, int s, int m, int l, int f, int _sz){
    prefix = p;
    suffix = s;
    mx = m;
    last = l;
    first = f;
    sz = _sz;
  }

  obj(){};
};

obj merge(obj l, obj r){
  obj ret = obj();
  ret.prefix = l.prefix;
  if(l.prefix == l.sz && l.last <= r.first) ret.prefix = l.sz + r.prefix;
  ret.suffix = r.suffix;
  if(r.suffix == r.sz && l.last <= r.first) ret.suffix = r.sz + l.suffix;
  ret.last = r.last;
  ret.first = l.first;
  ret.mx = max(l.mx, r.mx);
  if(l.last <= r.first) ret.mx = max(ret.mx, l.suffix + r.prefix);
  ret.sz = l.sz + r.sz;
  return ret;
}

obj seg[4 * 555555][2];
void build(int idx, int s, int e){
  if(s == e){
    REP(i, 2) { 
      bool f = i ^ (S[s] == '<');
      seg[idx][i] = obj(1, 1, 1, f, f, 1);
    }
    return;
  }

  int mid = (s + e) / 2;
  build(idx * 2 + 1, s, mid);
  build(idx * 2 + 2, mid + 1, e);
  REP(i, 2){
    seg[idx][i] = merge(seg[idx * 2 + 1][i], seg[idx * 2 + 2][i]);
  }
}


bool lzy[4 * 555555];
void propagate(int idx, int s, int e){
  if(lzy[idx] == 0) return;
  lzy[idx] = 0;
  if(s == e) return;
  lzy[idx * 2 + 1] ^= 1;
  swap(seg[idx * 2 + 1][0], seg[idx * 2 + 1][1]);
  lzy[idx * 2 + 2] ^= 1;
  swap(seg[idx * 2 + 2][0], seg[idx * 2 + 2][1]);
}
void segset(int idx, int s, int e, int st, int ed){
  if(lzy[idx]) propagate(idx, s, e);
  if(s == st && e == ed){
    lzy[idx] = 1;
    swap(seg[idx][0], seg[idx][1]);
    return;
  }
  int mid = (s + e) / 2;
  if(ed <= mid) segset(idx * 2 + 1, s, mid, st, ed);
  else if(st > mid) segset(idx * 2 + 2, mid + 1, e, st, ed);
  else {
    segset(idx * 2 + 1, s, mid, st, mid);
    segset(idx * 2 + 2, mid + 1, e, mid + 1, ed);
  }
  REP(i, 2) seg[idx][i] = merge(seg[idx * 2 + 1][i], seg[idx * 2 + 2][i]);
}
obj query(int idx, int s, int e, int st, int ed){
  if(lzy[idx]) propagate(idx, s, e);
  if(s == st && e == ed){
    return seg[idx][0];
  }
  int mid = (s + e) / 2;
  if(ed <= mid) return query(idx * 2 + 1, s, mid, st, ed);
  else if(st > mid) return query(idx * 2 + 2, mid + 1, e, st, ed);
  else return merge(
      query(idx * 2 + 1, s, mid, st, mid),
      query(idx * 2 + 2, mid + 1, e, mid + 1, ed));
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, q; cin >> n >> q;
  cin >> S;
  build(0, 0, n-1);
  while(q--){
    int l, r; cin >> l >> r;
    l--; 
    r--;
    segset(0, 0, n-1, l, r);
    obj t = query(0, 0, n-1, l, r);
    cout << t.mx << endl;
  }
}