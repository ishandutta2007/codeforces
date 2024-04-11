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

double dp[2001][2001][2][2], H, P;
int vis[2001][2001][2][2];
int lft[2001], rgt[2001], ar[2011];

double go(int l, int r, int fl, int fr){
    if(l > r) return 0.0;
    if(l == r) {
        double ret = 0.0;
        if(fl == 0) ret += min((double)(ar[l] - ar[l-1]), H) * P;
        else ret += min((double)(ar[l] - ar[l-1] - H), H) * P;
        if(fr == 0) ret += min((double)(ar[l+1] - ar[l]), H) * (1.0 - P);
        else ret += min((double)(ar[l+1] - ar[l] - H), H) * (1.0 - P);

        return ret;
    }


    double &ret = dp[l][r][fl][fr];
    if(vis[l][r][fl][fr]) return ret;
    vis[l][r][fl][fr] = 1;
    ret = 0.0;

    // left left
    if(fl == 0) ret += min((double)(ar[l] - ar[l-1]), H) * P;
    else ret += min((double)(ar[l] - ar[l-1] - H), H) * P;
    ret += go(l + 1, r, 0, fr) * P;



    // left right
    if(rgt[l] > r){
        if(fr == 0) ret += min((double)(ar[r+1] - ar[r]), H) * (1.0 - P);
        else ret += min((double)(ar[r+1] - ar[r] - H), H) * (1.0 - P);
        ret += (double)(ar[r] - ar[l]) * (1.0 - P);
    } else {
        ret += (go(rgt[l], r, 1, fr) + (double)(ar[rgt[l]-1] - ar[l] + H) ) * (1.0 - P);
    }

    // right left
    if(lft[r] < l){
        if(fl == 0) ret += min((double)(ar[l] - ar[l-1]), H) * P;
        else ret += min((double)(ar[l] - ar[l-1] - H), H) * P;
        ret += (double)(ar[r] - ar[l]) * P;
    } else {
        ret += (go(l, lft[r], fl, 1) + (double)(ar[r] - ar[lft[r]+1] + H) ) * P;
    }

    // right right
    if(fr == 0) ret += min((double)(ar[r+1] - ar[r]), H) * (1.0 - P);
    else ret += min((double)(ar[r+1] - ar[r] - H), H) * (1.0 - P);
    ret += go(l, r-1, fl, 0) * (1.0 - P);

    ret /= 2.0;

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n >> H >> P;

    FOR(i, 1, n+1) cin >> ar[i];

    sort(ar + 1, ar + n + 1);

    ar[0] = -mod;
    ar[n+1] = mod;
    for(int i = 2; i <= n; i++){
        if(ar[i] - ar[i-1] < H) lft[i] = lft[i-1];
        else lft[i] = i-1;
    }
    rgt[n] = n+1;
    for(int i = n-1; i >= 1; i--){
        if(ar[i+1] - ar[i] < H) rgt[i] = rgt[i + 1];
        else rgt[i] = i+1;
    }

    cout << fixed << setprecision(10) << go(1, n, 0, 0) << endl;
}