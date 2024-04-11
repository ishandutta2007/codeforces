/*********************************************************************\
   |--\        ---       /\        |-----------| -----   /-------|    |
   |   \        |       /  \       |               |    /             |
   |    \       |      /    \      |               |   |              |
   |     \      |     /      \     |               |   |----|         |
   |      \     |    / ------ \    |-------|       |        |-----|   |
   |       \    |   /          \   |               |              |   |
   |        \   |  /            \  |               |              /   |
  ---        -------            ------           ----- |---------/    |
                                                                      |
    codeforces = nfssdq  ||  topcoder = nafis007                      |
    mail = nafis_sadique@yahoo.com || nfssdq@gmail.com                |
    IIT,Jahangirnagar University(41)                                  |
                                                                      |
**********************************************************************/

#include <bits/stdc++.h>

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

vector < int > prime;
int isp[4001], tmp[500001][10], cc[500001], val[1<<10];
int cnt[10000001], ar[500001], two[500001];
int mob[10000001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i = 2; i <= 4000; i++){
        if(isp[i] == 0){
            for(int j = i * 2; j <= 4000; j += i) isp[j] = 1;
            prime.pb(i);
        }
    }
    two[0] = 1;
    FOR(i, 1, 500001) two[i] = (two[i-1] * 2ll) % mod;

    REP(i, 1<<10){
        if(__builtin_popcount(i) % 2 == 0) val[i] = 1;
        else val[i] = -1;
    }

    int n; cin >> n;
    REP(i, n){
        cin >> ar[i];
        int p = ar[i];
        REP(j, prime.size()){
            if(p % prime[j] == 0) {
                tmp[i][cc[i]++] = prime[j];
            }
            while(p % prime[j] == 0) p /= prime[j];
        }
        if(p > 1) {
            tmp[i][cc[i]++] = p;
        }
        REP(j, 1<<cc[i]){
            int v = 1;
            REP(k, cc[i]){
                if(j & 1<<k) v *= tmp[i][k];
            }
            cnt[v]++;
            mob[v] = val[j];
        }
    }

    LL tot = 0;
    FOR(i, 2, 10000001){
        tot = (tot - mob[i] * (two[cnt[i]] - 1) + mod) % mod;
    }

    LL res = 0;

    REP(i, n){
        res += tot;
        FOR(j, 1, 1<<cc[i]){
            int v = 1;
            REP(k, cc[i]){
                if(j & 1<<k) v *= tmp[i][k];
            }
            res = (res + mob[v] * (two[cnt[v]] - 1) + mod) % mod;
//            cout << i << " " << j << " " << v << " " << cnt[v] << endl;
        }
    }

//    cout << res << " " << tot << endl;


    cout << res << endl;

}