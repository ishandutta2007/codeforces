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

int cnt[111];
char S[555555];
LL seg[4 * 555555][2][2];
void insert(int idx, int s, int e, int p){
  if(s == e){
    REP(i, 2) seg[idx][i][i^1] = 1;
    seg[idx][0][0] = cnt[S[p] - '0'];
    return;
  }
  int mid = (s + e) / 2;
  if(p <= mid) insert(idx * 2 + 1, s, mid, p);
  else insert(idx * 2 + 2, mid + 1, e, p);
  REP(i, 2) REP(j, 2){
    seg[idx][i][j] = 0;
    seg[idx][i][j] += ((seg[idx * 2 + 1][i][0] * seg[idx * 2 + 2][0][j]) % mod);
    if(S[mid] == '1') seg[idx][i][j] += ((seg[idx * 2 + 1][i][1] * seg[idx * 2 + 2][1][j]) % mod) * cnt[(S[mid] - '0') * 10 + S[mid+1] - '0'];
    seg[idx][i][j] %= mod;
  }
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  REP(i, 10) REP(j, 10) cnt[i+j]++;
  int n, m; cin >> n >> m;
  cin >> S;
  REP(i, n) insert(0, 0, n-1, i);
  while(m--){
    int p; char c; cin >> p >> c;
    S[p-1] = c;
    insert(0, 0, n-1, p-1);
    cout << seg[0][0][0] << endl;
  }
}