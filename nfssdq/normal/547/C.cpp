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

vector < int > prime[500001];
int isp[500001];
LL cnt[500001], mob[500001], ar[500001], on[500001];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i = 2; i <= 500000; i++){
        if(isp[i] == 0){
            for(int j = i; j <= 500000; j += i) {
                isp[j] = 1;
                prime[j].pb(i);
            }
        }
    }
    int n, q; cin >> n >> q;
    FOR(i, 1, n+1) cin >> ar[i];
    LL res = 0, t = 0;
    REP(i, q){
        int v; cin >> v;
        if(on[v]){
            REP(j, 1<<prime[ ar[v] ].size()){
                LL p = 1, c = 0;
                REP(k, prime[ ar[v] ].size()){
                    if(j & 1<<k){
                        p *= prime[ ar[v] ][k];
                        c++;
                    }
                }
                if(p == 1) continue;
                if(c % 2 == 1){
                    cnt[p]--;
                    res -= cnt[p];
                } else {
                    cnt[p]--;
                    res += cnt[p];
                }
            }
            on[v] = 0;
            t--;
        } else {
            on[v] = 1;
            t++;
            REP(j, 1<<prime[ ar[v] ].size()){
                LL p = 1, c = 0;
                REP(k, prime[ ar[v] ].size()){
                    if(j & 1<<k){
                        p *= prime[ ar[v] ][k];
                        c++;
                    }
                }
                if(p == 1) continue;
                if(c % 2 == 1){
                    res += cnt[p];
                    cnt[p]++;
                } else {
                    res -= cnt[p];
                    cnt[p]++;
                }
            }
        }
        LL out = t * (t - 1);
        out /= 2ll; out -= res;
        cout << out << endl;
    }

}