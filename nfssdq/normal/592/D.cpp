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


vector < int > vc[123457];
int on[123457], off[123457], deg[123457], vis[123457];
int ar[123457], cnt[123457];
queue < int > Q;
int res = 0, id = inf;
void dfs(int c, int p){
    REP(i, vc[c].size()){
        if(vc[c][i] == p || off[vc[c][i]]) continue;
        dfs(vc[c][i], c);
        ar[c] = max(ar[c], 1 + ar[vc[c][i]]);
    }
}
void dfs1(int c, int p, int mx){
    int mx1 = 0;
    REP(i, vc[c].size()){
        if(vc[c][i] == p || off[vc[c][i]]) continue;
        if(ar[vc[c][i]]+1 >= mx){
            mx1 = mx;
            mx = ar[vc[c][i]]+1;
        } else if(ar[vc[c][i]]+1 >= mx1){
            mx1 = ar[vc[c][i]]+1;
        }
    }
    if(on[c] && mx >= res){
        if(mx > res) {
            res = mx;
            id = c;
        } else if(mx == res && id > c){
            id = c;
        }
    }
    REP(i, vc[c].size()){
        if(vc[c][i] == p || off[vc[c][i]]) continue;
        if(ar[vc[c][i]]+1 == mx) dfs1(vc[c][i], c, mx1 + 1);
        else dfs1(vc[c][i], c, mx + 1);
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    REP(i, n-1){
        int x, y; cin >> x >> y;
        vc[x].pb(y);
        vc[y].pb(x);
        deg[x]++; deg[y]++;
    }
    REP(i, m){
        int x; cin >> x;
        on[x] = 1;
    }
    FOR(i, 1, n+1){
        if(on[i] == 0 && deg[i] == 1) Q.push(i);
    }
    while(!Q.empty()){
        int c = Q.front(); Q.pop();
        off[c] = 1;
        vis[c] = 1;
        REP(i, vc[c].size()){
            if(vis[ vc[c][i] ]) continue;
            deg[vc[c][i]]--;
            if(on[vc[c][i]] == 0 && deg[vc[c][i]] == 1) Q.push(vc[c][i]);
        }
    }

    int cnt = 0, last = -1;
    FOR(i, 1, n+1){
        if(off[i] == 0) {
            if(on[i])last = i;
            cnt++;
        }
    }
    dfs(last, 0);
    dfs1(last, 0, 0);
    cout << id << endl << cnt*2-2 - res << endl;
}