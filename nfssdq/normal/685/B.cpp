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

typedef pair < pair < int, int >, int > piii;
priority_queue < piii, vector<piii>, greater<piii> > pq[300001];
vector < int > vc[300001];
int res[300001], sz[300001], mx[300001];
void dfs(int c, int p){
    sz[c] = 1;
    int mxsz = 0, mxid = c;
    REP(i, vc[c].size()){
        if(vc[c][i] == p) continue;
        dfs(vc[c][i], c);
        sz[c] += sz[ vc[c][i] ];
        mx[c] = max(mx[c], sz[ vc[c][i] ]);
        if(pq[ vc[c][i] ].size() > mxsz){
            mxsz = pq[ vc[c][i] ].size();
            mxid = vc[c][i];
        }
    }

    swap(pq[c], pq[mxid]);
    pq[c].push(mp(mp(mx[c], sz[c]), c));
    REP(i, vc[c].size()){
        if(vc[c][i] == p || vc[c][i] == mxid) continue;
        while(!pq[vc[c][i]].empty()){
            pq[c].push(pq[vc[c][i]].top());
            pq[vc[c][i]].pop();
        }
    }

    while(!pq[c].empty()){
        if(pq[c].top().xx.yy * 2 < sz[c]) pq[c].pop();
        else break;
    }
    res[c] = pq[c].top().yy;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q;
    FOR(i, 2, n+1) {
        int x; cin >> x;
        vc[x].pb(i);
    }

    dfs(1, 0);
    while(q--){
        int x; cin >> x;
        cout << res[x] << "\n";
    }
}