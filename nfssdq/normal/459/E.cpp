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
#define PI         2.0*acos(0.0)
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

vector < int > dp[300001];
int cnt[300001];
vector < pair < int, int > > vc[300001];
int BS(int c, int p){
    int lo = 0, hi = vc[c].size() - 1, mid = (lo + hi) / 2;
    if(p >= vc[c][hi].xx) return hi + 1;
    if(p < vc[c][lo].xx) return 0;
    while(lo < mid){
        if(vc[c][mid].xx > p) hi = mid;
        else lo = mid + 1;
        mid = (lo + hi) / 2;
    }
    if(vc[c][mid].xx <= p) mid++;
    return mid;
}
int dfs(int c, int p){
    if(vc[c].size() == 0) return 0;
    int lb = BS(c, p);
//    cout << c << " " << p << " " << lb << endl;
    while(cnt[c] > lb){
        dp[c][cnt[c] - 1] = 1 + dfs(vc[c][cnt[c]-1].yy, vc[c][cnt[c]-1].xx);
        dp[c][cnt[c] - 1] = max(dp[c][cnt[c] - 1], dp[c][cnt[c]]);
        cnt[c]--;
    }
    return dp[c][lb];
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a = 0,b,c,d,e = 0,f = 0,g,h = 0,x,y,z;
    cin >> a >> b;
    REP(i, b){
        cin >> c >> d >> e;
        vc[c].pb(mp(e, d));
        dp[c].pb(0);
    }
    FOR(i, 1, a + 1) vsort(vc[i]);
    FOR(i, 1, a + 1) cnt[i] = vc[i].size();
    FOR(i, 1, a + 1) dp[i].pb(0);
    f = 0;
    for(int i = 1; i <= a; i++){
        f = max(f, (LL)dfs(i, 0));
    }
    cout << f << endl;
}