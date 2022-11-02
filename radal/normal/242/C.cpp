#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<ll,ll> pll;
const long long int N=2e5+20,mod = 1e9+7,inf=8e18,maxk = 1e5+20;
const long double eps = 0.0001;
pair<int,pll> ve[N];
int n,x3,y3,y2,x2;
map<pll,vector<pll>> mp;
set<pll> st,st2;
map<pll,ll> d;
void bfs(){
    st2.insert({x2,y2});
    d[{x2,y2}] = 0;
    queue<pll> q;
    q.push({x2,y2});
    while(!q.empty()){
        pll p = q.front();
        q.pop();
        for (pll u : mp[p]){
            if (st2.find(u) == st2.end()){
                st2.insert(u);
                d[u] = d[p]+1;
                q.push(u);
                if(u.X == x3 && u.Y == y3) return;
            }
        }
    }
}
int main(){
    pll p,p2;
    cin >> x2 >> y2 >> x3 >> y3;
    cin >> n;
    rep(i,0,n){
        cin >> ve[i].X >> ve[i].Y.X >> ve[i].Y.Y;
        rep(j,ve[i].Y.X,ve[i].Y.Y+1) st.insert({ve[i].X,j});
    }
    for (auto it = st.begin(); it != st.end(); it++){
        ll r = (*it).X,i = (*it).Y;
     //   if (r == 5 && i== 3) cout << j << endl;
        if (st.find({r,i-1}) != st.end()){
            p = {r,i};
            p2 = {r,i-1};
            mp[p].pb(p2);
            mp[p2].pb(p);
        }
        if (st.find({r-1,i-1}) != st.end()){
            mp[{r,i}].pb({r-1,i-1});
            mp[{r-1,i-1}].pb({r,i});
        }
        if (st.find({r-1,i}) != st.end()){
            mp[{r,i}].pb({r-1,i});
            mp[{r-1,i}].pb({r,i});
        }
        if (st.find({r+1,i-1}) != st.end()){
            mp[{r,i}].pb({r+1,i-1});
            mp[{r+1,i-1}].pb({r,i});
        }
    }
    p = {5,3};
    bfs();
    if (st2.find({x3,y3}) == st2.end()){
        cout << -1;
        return 0;
    }
    cout << d[{x3,y3}];
    return 0;
}