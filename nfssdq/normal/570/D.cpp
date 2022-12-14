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


int St[500001], Ed[500001], lvl[500001], pre[500001];
vector < int > vc[500001];
vector < pair < int, int > > ar[500001];
string ss;
int t = 0;
void dfs(int c, int d){
    St[c] = ++t;
    lvl[c] = d;
    ar[d].pb(mp(t, 1<<(ss[c-1]-'a')));
    REP(i, vc[c].size()){
        dfs(vc[c][i], d + 1);
    }
    Ed[c] = t;
}
int FindLo(int d, int st){
    if(ar[d].size() == 0) return 0;
    if(ar[d][ar[d].size()-1].xx < st) return ar[d].size();
    int lo = 0, hi = ar[d].size() - 1, mid = (lo + hi) / 2;
    while(lo < mid){
        if(ar[d][mid].xx < st) lo = mid + 1;
        else hi = mid;
        mid = (lo + hi) / 2;
    }
    if(ar[d][mid].xx < st) mid++;
    return mid;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    FOR(i, 2, n+1){
        cin >> pre[i];
        vc[pre[i]].pb(i);
    }
    cin >> ss;
    dfs(1, 1);

    for(int i = 1; i <= n; i++){
        FOR(j, 1, ar[i].size()){
            ar[i][j].yy ^= ar[i][j-1].yy;
        }
    }

    while(m--){
        int v, h;
        cin >> v >> h;
        int p1 = FindLo(h, St[v]), p2 = FindLo(h, Ed[v]+1) - 1;
//        cout << p1 << " " << p2 << endl;
        if(p2 < p1){
            cout << "Yes\n";
            continue;
        }
        int v1 = ar[h][p2].yy;
        if(p1 > 0) v1 ^= ar[h][p1-1].yy;
        if(__builtin_popcount(v1) <= 1) cout << "Yes\n";
        else cout << "No\n";
    }
}