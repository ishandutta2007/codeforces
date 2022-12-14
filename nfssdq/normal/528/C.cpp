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


vector < int > vc[100001], vp[100001], circuit;
int deg[100001], vis[500001], cnt[100001];
void dfs(int c){
    while(cnt[c] < vp[c].size()){
        int i = cnt[c];
        cnt[c]++;
        if(vis[ vp[c][i] ]) continue;
        vis[ vp[c][i] ] = 1;
        dfs(vc[c][i]);
    }
    circuit.pb(c);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    REP(i, m){
        int x, y;
        cin >> x >> y;
        vc[x].emplace_back(y);
        vc[y].emplace_back(x);
        vp[x].emplace_back(i);
        vp[y].emplace_back(i);
        deg[x]++; deg[y]++;
    }
    int last = -1;
    FOR(i, 1, n+1){
        if(deg[i]%2 == 1) {
            if(last == -1) last = i;
            else {
                vc[last].emplace_back(i);
                vc[i].emplace_back(last);
                vp[i].emplace_back(m);
                vp[last].emplace_back(m);
                deg[last]++;
                deg[i]++;
                last = -1;
                m++;
            }
        }
    }
    if(m % 2 == 1){
        vc[1].emplace_back(1);
        vc[1].emplace_back(1);
        vp[1].emplace_back(m);
        vp[1].emplace_back(m);
        deg[1] += 2;
        m++;
    }
    dfs(1);
    cout << m << endl;
    for(int i = 1; i < circuit.size(); i += 2){
        cout << circuit[i - 1] << " " << circuit[i] << endl;
        cout << circuit[i + 1] << " " << circuit[i] << endl;
    }

}