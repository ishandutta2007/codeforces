#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<string>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<climits>
#include<complex>
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
    }
    return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}


vector < int > vc[1001], ini;

pair<int,int> check(){
    if(ini.size() == 0) return mp(0, 100000);
    cout << "? " << ini.size();
    REP(i, ini.size()) cout << " " << ini[i];
    cout << endl;
    fflush(stdout);
    int p, d; cin >> p >> d;
    return mp(p, d);
}

int dist[1001], st[1001], ed[1001], CNT;
void dfs(int c, int p, int d){
    dist[c] = d;
    st[c] = ++CNT;
    REP(i, vc[c].size()) {
        if(vc[c][i] != p) dfs(vc[c][i], c, d + 1);
    }
    ed[c] = CNT;
}

void go(){
    CNT = 0;
    int n; cin >> n;
    FOR(i, 1, n+1) vc[i].clear();
    REP(i, n-1){
        int x, y; cin >> x >> y;
        vc[x].pb(y);
        vc[y].pb(x);
    }

    ini.clear();
    REP(i, n) ini.push_back(i+1);
    pair<int,int> p = check();

    int root = p.xx, dis = p.yy;
    dfs(root, 0, 0);

    int lo = 0, hi = dis, nroot = root;
    while(lo < hi){
        int mid = (lo + hi) / 2; mid++;
        ini.clear();
        FOR(i, 1, n+1) {
            if(dist[i] == mid && st[nroot] <= st[i] && st[i] <= ed[nroot]) ini.pb(i);
        }
        p = check();
        if(p.yy > dis) hi = mid - 1;
        else {
            lo = mid;
            nroot = p.xx;
        }
    }

    dfs(nroot, 0, 0);
    ini.clear();
    FOR(i, 1, n+1){
        if(dist[i] == dis && st[root] <= st[i] && st[i] <= ed[root]) ini.pb(i);
    }
    p = check();
    cout << "! " << nroot << " " << p.xx << endl;
    string S; cin >> S;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    FOR(ts, 1, T+1){
        go();
    }
}