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

vector < int > vc[1000001];
LL ar[1000001], mob[1000001], isp[1000001], val[1000001];
LL tmp[1000001], pre[1000001];

LL fact[1000001], inv[1000001];
LL ncr(int n, int r){
    if(n < r) return 0;
    LL ret = (fact[n] * inv[r]) % mod;
    return (ret * inv[n-r]) % mod;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i = 1; i <= 1000000; i++){
        for(int j = i; j <= 1000000; j += i) vc[j].pb(i);
    }

    FOR(i, 1, 1000001) mob[i] = 1;
    for(int i = 2; i <= 1000000; i++){
        if(isp[i] == 0){
            for(int j = i; j <= 1000000; j += i){
                mob[j] *= -1;
                if(i <= 1000 && (j % (i*i)) == 0) mob[j] = 0;
                isp[j] = 1;
            }
        }
    }

    FOR(i, 1, 1000001) mob[i] = (mob[i] + mod) % mod;

    for(int i = 1; i <= 1000000; i++){
        for(int j = 0; j < vc[i].size(); j++){
            pre[i] = (pre[i] + mob[i/vc[i][j]] * (LL)vc[i][j]) % mod;
        }
    }

    fact[0] = 1;
    for(LL i = 1; i <= 1000000; i++) fact[i] = (fact[i - 1] * i) % mod;
    REP(i, 1000001) inv[i] = modinverse(fact[i], mod);

    int n, K, q; cin >> n >> K >> q;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        tmp[x]++;
    }

    LL sum = 0;
    for(int i = 1000000; i >= 1; i--){
        for(int j = i; j <= 1000000; j += i) val[i] += tmp[j];
        for(int j = i; j <= 1000000; j += i){
            ar[i] = (ar[i] + ncr(val[j], K) * mob[j/i]) % mod;
        }
        sum = (sum + ar[i] * (LL)i) % mod;
    }

    while(q--){
        int v; cin >> v;
        for(int i = vc[v].size() - 1; i >= 0; i--){
            int x = vc[v][i];
            LL p = (ncr(val[x]+1, K) + mod - ncr(val[x], K)) % mod;
            sum = (sum + p * pre[x]) % mod;
            val[x]++;
        }

        cout << sum << endl;
    }
}