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

int isp[2000001], pid[2000001];
vector < int > prime, factor[2000001];
vector < int > vc[100001], last[2000001], query[100001];
int ar[100001], res[100001], deep[100001];
pair < int, pair < int, int > > pp[100001];
void dfs(int c, int p){
    deep[c] = 1 + deep[p];
    if(query[c].size() > 0){
        int b = -1;
        REP(i, factor[ar[c]].size()){
            int a = factor[ar[c]][i];
            if(last[a].size() == 0) continue;
            int c = last[a][last[a].size() - 1];
            if(b == -1) b = c;
            else if(deep[b] < deep[c]) b = c;
        }
        REP(i, query[c].size()) res[query[c][i]] = b;
    }
    REP(i, factor[ar[c]].size()){
        int a = factor[ar[c]][i];
        last[a].pb(c);
    }
    REP(i, vc[c].size()){
        if(vc[c][i] != p) dfs(vc[c][i], c);
    }
    REP(i, factor[ar[c]].size()){
        int a = factor[ar[c]][i];
        last[a].pop_back();
    }
}
main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a,b,c,d = 0,e,f = 0,g = 0,h = 0,x,y,z;
    for(int i = 2; i <= 2000000; i++){
        if(isp[i] == 0){
            for(int j = i; j <= 2000000; j += i) {
                isp[j] = 1;
                factor[j].pb(i);
            }
            prime.pb(i);
        }
    }
    REP(i, prime.size()){
        pid[prime[i]] = i;
    }
    cin >> a >> b;
    FOR(i, 1, a + 1) cin >> ar[i];
    REP(i, a - 1){
        cin >> c >> d;
        vc[c].pb(d);
        vc[d].pb(c);
    }
    pp[0].xx = 2;
    FOR(i, 1, b + 1){
        cin >> pp[i].xx >> pp[i].yy.xx;
        if(pp[i].xx == 2){
            cin >> pp[i].yy.yy;
        }
    }
    memset(res, -1, sizeof res);
    REP(i, b + 1){
        if(pp[i].xx == 2){
            ar[pp[i].yy.xx] = pp[i].yy.yy;
            for(int j = 0; j <= a; j++) query[i].clear();
            FOR(j, 1, 2000001) last[i].clear();
            c = i;
            for(int j = i + 1; j <= b; j++){
                if(pp[j].xx == 2) break;
                c = j;
                query[pp[j].yy.xx].pb(j);
            }
            dfs(1, 0);
            for(int j = i + 1; j <= c; j++) cout << res[j] << endl;
            i = c;
        }
    }
}