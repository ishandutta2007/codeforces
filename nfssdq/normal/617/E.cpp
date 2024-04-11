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
#include<unordered_set>

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

int A[100001], B[100001];
int cnt[300][100001], ar[1<<20], val[300];
LL res[100001];

vector < pair < int, pair < int, int > > > vc[ 100001 ];

pair < int, int > pp[100001];

vector < int > vp[100001][2];

unordered_set < int > S;

int sum1[301][401];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    FOR(i, 1, n+1){
        cin >> A[i];
        A[i] ^= A[i-1];
        B[i] = A[i] ^ k;
    }

    int lim = 400;
    for(int i = 1; i <= n; i++){
        if((i % lim) == lim - 1){
            int s = (i / lim) * lim;
            for(int j = s; j < i; j++){
                for(int k = j + 1; k <= i; k++){
                    if(A[j] == B[k]) {
                        val[ (i/lim) ]++;
                        sum1[ (i/lim) ][j%lim]++;
                    }
                }
            }

            for(int j = s; j <= i; j++) ar[ B[j] ]++;

            for(int j = s - 1; j >= 0; j--){
                cnt[ (i/lim) ][j] = cnt[ (i/lim) ][j+1] + ar[ A[j] ];
            }

            for(int j = lim - 2; j >= 0; j--) sum1[i/lim][j] += sum1[i/lim][j+1];

            for(int j = s; j <= i; j++) ar[ B[j] ]--;
        }
    }

    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        pp[i] = mp(x, y);

        int l = (x / lim), r = (y / lim);
        if(l == r){
            vc[pp[i].xx-1].pb(mp(i, pp[i]));
            vp[ pp[i].xx ][0].pb(i);
            vp[ pp[i].yy ][1].pb(i);
        } else {
            vc[pp[i].xx-1].pb(mp(i, mp(r*lim, pp[i].yy)));
            vp[ r*lim ][0].pb(i);
            vp[ pp[i].yy ][1].pb(i);
            res[i] += sum1[l][pp[i].xx%lim];

            for(int j = x; ; j++){
                if(A[x-1] == B[j]) res[i]++;
                if((j%lim) == lim-1) break;
            }

            for(int j = l + 1; j < r; j++){
                res[i] += val[j] + cnt[ j ][ pp[i].xx - 1 ];
            }
        }
    }

    for(int i = 0; i <= n; i++){
        REP(j, vc[i].size()){
            for(int k = vc[i][j].yy.xx; k <= vc[i][j].yy.yy; k++){
                res[ vc[i][j].xx ] -= ar[ B[k] ];
            }
        }

        for(int j = 0; j < vp[i][0].size(); j++){
            S.insert(vp[i][0][j]);
        }

        for(auto &v: S){
            res[v] += ar[B[i]];
        }

        ar[A[i]]++;

        for(int j = 0; j < vp[i][1].size(); j++) {
            S.erase(vp[i][1][j]);
        }
    }

    FOR(i, 1, m+1) cout << res[i] << "\n";
}