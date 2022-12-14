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
#define mod        1000000007ll
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


map<int,int> id;
int A[200001], B[200011], cnt[200011], lft[200011];

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while(T--){
    int n; cin >> n;
    id.clear();
    FOR(i, 1, n+1){
      cin >> A[i];
      id[A[i]] = 1;
    }
    int cc = 0;
    for(auto &v: id) v.yy = ++cc;
    FOR(i, 1, cc+2) B[i] = cnt[i] = lft[i] = 0;
    FOR(i, 1, n+1) {
      A[i] = id[A[i]];
      cnt[A[i]]++;
    }
    
    int res = 0;
    for(int i = n; i >= 1; i--){
      int v = 1 + B[A[i]];
      if(cnt[A[i]+1] == 0) v = max(v, 1 + B[A[i]+1]);
      else v = max(v, 1 + lft[A[i]+1]);
      B[A[i]] = v;
      cnt[A[i]]--;
      lft[A[i]]++;
      res = max(res, v);
    }

    cout << n-res << endl;
  }  
}