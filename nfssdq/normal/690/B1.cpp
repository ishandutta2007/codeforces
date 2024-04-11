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


char pp[55][55];
int nxt[4][2] = { {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    REP(i, n) cin >> pp[i];

    int cnt = 0;
    int mxx = -1, mxy = -1, mnx = 55, mny = 55;
    REP(i, n){
        REP(j, n){
            if(pp[i][j] == '4'){
                mxx = max(mxx, i);
                mxy = max(mxy, j);
                mnx = min(mnx, i);
                mny = min(mny, j);
                cnt++;
            }
        }
    }

    if(mxx == -1 || cnt != (mxx-mnx+1)*(mxy-mny+1)){
        cout << "No" << endl;
        return 0;
    }


    for(int i = mnx - 1; i <= mxx + 1; i++){
        for(int j = mny - 1; j <= mxy+1; j++){
            if(i < 0 || i >= n || j < 0 || j >= n || pp[i][j] == '4') continue;
            int cc = 0;
            REP(k, 4){
                int x = i + nxt[k][0];
                int y = j + nxt[k][1];
                if(mnx-1 <= x && x <= mxx+1 && mny-1 <= y && y <= mxy+1) cc++;
            }
            if(pp[i][j]-'0' != cc){
                cout << "No" << endl;
                return 0;
            }
        }
    }


    REP(i, n) REP(j, n){
        if(mnx-1 <= i && i <= mxx+1 && mny-1 <= j && j <= mxy+1) continue;
        if(pp[i][j] != '0'){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}