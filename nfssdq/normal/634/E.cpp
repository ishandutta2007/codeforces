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


vector < int > vc[200001];
int ar[200001], K;
int sz[200001], on[200001];
int dp[200001][2], mx, n;

void dfs1(int c, int p){
    sz[c] = 1;
    REP(i, vc[c].size()){
        if(vc[c][i] == p) continue;
        dfs1(vc[c][i], c);
        sz[c] += sz[vc[c][i]];
    }
}


void dfs(int m,int c, int p){
    dp[c][0] = dp[c][1] = 0;
    REP(i, vc[c].size()){
        if(vc[c][i] == p) continue;
        dfs(m, vc[c][i], c);
        if(sz[vc[c][i]] == dp[vc[c][i]][0])dp[c][0] += dp[vc[c][i]][0];
        else dp[c][1] = max(dp[c][1], dp[vc[c][i]][1]);
    }

    if(ar[c] < m){
        on[c] = 0;
        dp[c][0] = dp[c][1] = 0;
    } else {
        on[c] = 1;
        dp[c][0]++;
        dp[c][1] += dp[c][0];
    }
}


int chk = 0;
void go(int c, int p, int d0, int d1, int tot){
    int mxx1 = 0, mxx2 = 0, mxx3 = 0;
    if(d0 == tot) mxx1 += d0;
    else {
        if(d1 > mxx2){
            mxx3 = mxx2;
            mxx2 = d1;
        } else if(d1 > mxx3){
            mxx3 = d1;
        }
    }

    REP(i, vc[c].size()){
        if(vc[c][i] == p) continue;
        if(sz[vc[c][i]] == dp[vc[c][i]][0]) mxx1 += dp[vc[c][i]][0];
        else {
            if(dp[vc[c][i]][1] > mxx2){
                mxx3 = mxx2;
                mxx2 = dp[vc[c][i]][1];
            } else if(dp[vc[c][i]][1] > mxx3){
                mxx3 = dp[vc[c][i]][1];
            }
        }
    }

//    if(chk)cout << c << " " <<  mxx1 << " " << mxx2 << " " << mxx3 << endl;

    tot = n;
    if(on[c]){
        mxx1++;
        mxx2 += mxx1;
        mxx3 += mxx1;
        mx = max(mx, mxx2);
    } else {
        mxx1 = mxx2 = 0;
        REP(i, vc[c].size()){
            if(vc[c][i] == p) continue;
            go(vc[c][i], c, 0, 0, tot - sz[vc[c][i]]);
        }
        return;
    }

    REP(i, vc[c].size()){
        if(vc[c][i] == p) continue;
//        if(chk && c == 8) cout << vc[c][i] << " " << dp[vc[c][i]][0] << " " << sz[vc[c][i]] << " qqq" << endl;
        if(sz[vc[c][i]] == dp[vc[c][i]][0]) go(vc[c][i], c, mxx1-dp[vc[c][i]][0], mxx2-dp[vc[c][i]][0], tot-sz[vc[c][i]]);
        else if(mxx2-mxx1 == dp[vc[c][i]][1]) go(vc[c][i], c, mxx1, mxx3, tot-sz[vc[c][i]]);
        else go(vc[c][i], c, mxx1, mxx2, tot-sz[vc[c][i]]);
    }

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K;
    FOR(i, 1, n+1) cin >> ar[i];
    REP(i, n-1){
        int x, y; cin >> x >> y;
        vc[x].pb(y);
        vc[y].pb(x);
    }

    dfs1(1, 0);

//    chk = 1;
//    set0(on);
//    dfs(557321, 1, 0);
//    FOR(i, 1, n+1) cout << i << " " << dp[i][0] << " ppp " << dp[i][1] << endl;
//    go(1, 0, 0, 0, 0);
//    chk = 0;

    int lo = 1, hi = 1000000, mid = (lo + hi) / 2;
    while(lo < mid){
        set0(on);
        dfs(mid, 1, 0);
        mx = 0;
        go(1, 0, 0, 0, 0);
        if(mx >= K) lo = mid;
        else hi = mid - 1;
        mid = (lo + hi) / 2;
    }

    set0(on);
    dfs(mid+1, 1, 0);
    mx = 0;
    go(1, 0, 0, 0, 0);
    if(mx >= K) mid++;
    cout << mid << endl;

}