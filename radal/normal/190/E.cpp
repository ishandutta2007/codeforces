#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<int,int> pll;
const long long int N=5e5+30,mod = 1e9+7,inf=1e12;
const long double eps = 0.0001;
int n,m;
bool visited[N];
set <pll> st;
set <int> ve;
vector <int> g[N];
void bfs(int v,int t){
    g[t].pb(v);
    queue <int> q;
    q.push(v);
    visited[v] = 1;
    ve.erase(v);
    while (!q.empty()){
        int u = q.front();
        q.pop();
        bool f = 0;
        if (ve.empty()) break;
        for(auto it = ve.begin(); it != ve.end(); it){
            if (ve.empty()) return;
            if (f) it = ve.begin();
            f = 0;
            int i = *it;
            if (!visited[i] and st.find({min(i,u),max(i,u)}) == st.end()){
                q.push(i);
                visited[i] = 1;
                g[t].pb(i);
                it = ve.erase(it);
            }
            else it++;
            if (ve.empty()) return;
        }
    }
}
int main(){
    ios :: sync_with_stdio(0); cout.tie(0);
    cin >> n >> m;
    rep(i,0,m){
        int x,y;
        cin >> x >> y;
        if (x > y) swap(x,y);
        st.insert({x,y});
    }
    if (m < n-1){
        cout << 1 << endl << n << ' ';
        rep(i,1,n+1) cout << i << ' ';
        return 0;
    }
    rep(i,1,n+1) ve.insert(i);
    int t = 0;
    rep(i,1,n+1){
        if (!visited[i]){
            t++;
          //  ve.erase(i);
            bfs(i,t);
        }
    }
    cout << t << endl;
    rep(i,1,t+1){
        cout << g[i].size() << ' ';
        for (int u : g[i]) cout << u << ' ';
        cout << endl;
    }
    return 0;
}