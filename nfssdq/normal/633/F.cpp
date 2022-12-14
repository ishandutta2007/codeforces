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

vector < int > vc[100001];
LL dp[100001][2][3], ar[100001];

LL go(int c, int up, int t, int p){
    LL &ret = dp[c][up][t];
    if(ret != -1) return ret;
    ret = 0;

    if(up){
        ret = ar[c];
        if(t)ret = max(ret, go(c, 0, t, p));
        LL mx1 = 0, mx2 = 0;
        REP(i, vc[c].size()){
            if(vc[c][i] == p) continue;
            ret = max(ret, ar[c] + go(vc[c][i], 1, t, c));
            if(t){
                LL v = go(vc[c][i], 0, t, c);
                if(v > mx1){
                    mx2 = mx1;
                    mx1 = v;
                } else if(v > mx2) mx2 = v;
            }
        }

        REP(i, vc[c].size()){
            if(vc[c][i] == p) continue;
            if(t == 0) break;
            LL v = go(vc[c][i], 0, t, c);
            if(v == mx1){
                ret = max(ret, ar[c] + go(vc[c][i], 1, 0, c) + mx2);
            } else {
                ret = max(ret, ar[c] + go(vc[c][i], 1, 0, c) + mx1);
            }
        }

        return ret;
    }

    if(t == 1){
        LL mx1 = 0, mx2 = 0;
        REP(i, vc[c].size()){
            if(vc[c][i] == p) continue;
            ret = max(ret, go(vc[c][i], 0, 1, c));
            LL v = go(vc[c][i], 1, 0, c);
            if(v > mx1){
                mx2 = mx1;
                mx1 = v;
            } else if(v > mx2){
                mx2 = v;
            }
        }
        ret = max(ret, ar[c] + mx1 + mx2);

        return ret;
    }

    LL mx1 = 0, mx2 = 0, mx3 = 0;
    LL mxx1 = 0, mxx2 = 0;
    REP(i, vc[c].size()){
        if(vc[c][i] == p) continue;
        ret = max(ret, go(vc[c][i], 0, 2, c));
        LL v = go(vc[c][i], 1, 1, c);
        if(v > mxx1) {
            mxx2 = mxx1;
            mxx1 = v;
        } else if(v > mxx2){
            mxx2 = v;
        }
    }
    ret = max(ret, ar[c] + mxx1);
    REP(i, vc[c].size()){
        if(vc[c][i] == p) continue;
        LL v = go(vc[c][i], 1, 1, c);
        if(v == mxx1) ret = max(ret, ar[c] + go(vc[c][i], 1, 0, c) + mxx2);
        else ret = max(ret, ar[c] + go(vc[c][i], 1, 0, c) + mxx1);
    }

    mxx1 = mxx2 = 0;
    REP(i, vc[c].size()){
        if(vc[c][i] == p) continue;
        LL v = go(vc[c][i], 0, 1, c);
        if(v > mxx1){
            mxx2 = mxx1;
            mxx1 = v;
        } else if(v > mxx2) mxx2 = v;

        v = go(vc[c][i], 1, 0, c);
        if(v > mx1){
            mx3 = mx2;
            mx2 = mx1;
            mx1 = v;
        } else if(v > mx2){
            mx3 = mx2;
            mx2 = v;
        } else if(v > mx3){
            mx3 = v;
        }
    }

    ret = max(ret, mxx1 + mxx2);
    ret = max(ret, ar[c] + mx1+mx2);

    REP(i, vc[c].size()){
        if(vc[c][i] == p) continue;
        LL v = go(vc[c][i], 1, 0, c);
        LL v1 = go(vc[c][i], 0, 1, c);
        if(v == mx1) ret = max(ret, ar[c] + mx2+mx3+v1);
        else if(v == mx2) ret = max(ret, ar[c] + mx1+mx3+v1);
        else ret = max(ret, ar[c] + mx1+mx2+v1);
    }
    return ret;

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    FOR(i, 1, n+1) cin >> ar[i];
    REP(i, n-1){
        int x, y; cin >> x >> y;
        vc[x].pb(y);
        vc[y].pb(x);
    }

    memset(dp, -1, sizeof dp);
    cout << go(1, 0, 2, 0) << endl;
}