#include<cstdio>
#include<cstring>
#include<cassert>
#include<vector>
#include<list>
#include<queue>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<typeinfo>
#include<locale>
#include<iterator>
#include<valarray>
#include<complex>
#include<climits>

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
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

LL ar[100001], dp[100001], mx[100001];
pair < LL, LL > query(LL m, int n){
    if(m == 0) return mp(0, 0);
    int c = upper_bound(ar + 1, ar + n + 1, m) - ar - 1;
    //if(m == 7) cout << c << " pp " << ar[c] << endl;
    pair < LL, LL > ret = mp(dp[c], mx[c]);
    LL v = m / ar[c];
    LL md = m % ar[c];

    ret.xx += v - 1;
    ret.yy += (v-1) * ar[c];

    pair < LL, LL > p = query(md, n);
    p.xx += v;
    p.yy += v * ar[c];
    if(p > ret) ret = p;

    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ar[1] = 1; dp[1] = mx[1] = 0;
    for(int i = 2; i <= 100000; i++){
        LL v = i;
        ar[i] = v * v * v;
        pair < LL, LL > p = query(ar[i]-1, i);
        dp[i] = p.xx;
        mx[i] = p.yy;
//        if(i <= 100) cout << dp[i] << " " << mx[i] << endl;
    }

    LL m; cin >> m;
    pair < LL, LL > p = query(m, 100000);
    cout << p.xx << " " << p.yy << endl;

    return 0;
}