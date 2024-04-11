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


pair < LL, LL > pp[100001];
LL ar[100001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    REP(i, n){
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        pp[i] = mp(x1+x2, y1+y2);
    }
    sort(pp, pp + n);

    LL res = -1;

    for(int i = 0; i <= k; i++){
        for(int j = n-k-1; j < n; j++){
            if(i+n-j-1 > k || i > j || i >= n || j < 0) continue;
            int cc = 0;
            for(int l = i; l <= j; l++){
                ar[cc++] = pp[l].yy;
            }
            sort(ar, ar + cc);


            int rem = k - (i+n-j-1);
            LL mn = 1ll<<50;
            for(int x = 0; x <= rem; x++){
                for(int y = cc-rem-1; y < cc; y++){
                    if(x+cc-1-y > rem || x > y || x >= n || y < 0) continue;
                    mn = min(mn, ar[y] - ar[x] + (ar[y]-ar[x])%2);
                }
            }

            mn = max(mn, 2ll);
            mn *= max(2ll, pp[j].xx - pp[i].xx + (pp[j].xx - pp[i].xx)%2);

            if(res == -1){
                res = mn;
            } else res = min(res, mn);
        }
    }

    cout << res/4ll << endl;

}