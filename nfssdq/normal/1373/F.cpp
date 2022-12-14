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

int A[1000001], B[1000001];

int st[1000001];

bool solve2(int n){
  int cc = 0;
  REP(i, n){
    if(A[i] <= B[i] && A[(i + n - 1) % n] > B[(i + n - 1) % n]){
      st[cc++] = i;
    }
  }
  if(cc == 0) return A[0] <= B[0];

  int last = -1;
  REP(i, cc){
    if(st[i] <= last) continue;
    int extra = 0;
    bool fl = true;
    for(int j = st[i]; j < st[i] + n; j++){
      if(B[j % n] + extra < A[j % n]){
        fl = false;
        break;
      }
      extra = min(B[j % n], B[j % n] + extra - A[j % n]);
      last = j;
    }
    if(fl) return true;
  }
  return false;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  FOR(ts, 1, T+1){
    int n; cin >> n;
    REP(i, n) cin >> A[i];
    REP(i, n) cin >> B[i];
    if(solve2(n)) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  
}