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

int par[100001];
int Find(int x){
    if(x == par[x]) return x;
    return par[x] = Find(par[x]);
}
void Union(int x, int y){
    int px = Find(x);
    int py = Find(y);
    if(px == py) return;
    par[px] = py;
}
vector < int > vc[100001], adj[100001];
struct data{
    int type, x, y;
} ar[100001];
int st[100001], ed[100001], cc = 0, tp[100001];
void dfs(int c){
    cc++;
    st[c] = cc;
    REP(i, adj[c].size()){
        dfs(adj[c][i]);
    }
    ed[c] = cc;
}
int res[100001];
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a = 0,b,c,d,e = 0,f = 0,g = 0,h = 0,x,y,z;
    cin >> a >> b;
    FOR(i, 1, a + 1) par[i] = tp[i] = i;
    REP(i, b){
        cin >> ar[i].type;
        if(ar[i].type == 1) {
            cin >> ar[i].x >> ar[i].y;
            tp[ar[i].x] = ar[i].y;
            adj[ar[i].y].pb(ar[i].x);
        }
        else if(ar[i].type == 2) cin >> ar[i].x;
        else {
            cin >> ar[i].x >> ar[i].y;
            vc[ar[i].y].pb(i);
        }
    }
    FOR(i, 1, a + 1) {
        if(tp[i] == i) dfs(i);
    }
    REP(i, b){
        if(ar[i].type == 1) Union(ar[i].x, ar[i].y);
        else if(ar[i].type == 2){
            f++;
            REP(j, vc[f].size()){
                c = vc[f][j];
                d = ar[c].x;
                int pc = Find(d);
                int pd = Find(ar[i].x);
                if(pc != pd) continue;
                if(st[d] <= st[ar[i].x] && st[ar[i].x] <= ed[d]) res[c] = 1;
            }
        } else {
            if(res[i]) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}