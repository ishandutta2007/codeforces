#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvvvi vector<vvvi>
#define vvvvvi vector<vvvvi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define loop(i,s,e) for(int i=s;i<e;i++)
#define chkmax(a,b) a = max((a),(b))
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 1e18, MOD=998244853, MAXN=4e3+5;\
struct node{
    node *prev,*next;
    int val;
};
int n=0,k;
vvii g;
vb edgecheck;
vi pos;
list<int> ans;
void dfs(list<int>::iterator it, int cur){
    for(;pos[cur]<g[cur].size();pos[cur]++){
        if (edgecheck[g[cur][pos[cur]].y]) continue;
        edgecheck[g[cur][pos[cur]].y] = 1;
        dfs(ans.insert(it, cur), g[cur][pos[cur]].x);
    }
}
bool solve(){
    vi odd;
    loop(i,0,n) if(g[i].size()&1) odd.pb(i);
    int start,end;
    if (odd.size()==0) start=end=0;
    else if (odd.size()==2) start=odd[0], end=odd[1];
    else return 0;
    edgecheck.resize(k-1,0); pos.resize(n,0);
    dfs(ans.begin(),start);
    ans.insert(ans.begin(),end);
    loop(i,0,k-1) if(!edgecheck[i]) return 0;
    return 1;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>k;
    vvi edge(k-1,vi(2,0));
    map<int,int> conv;
    loop(j,0,2) loop(i,0,k-1){
        cin>>edge[i][j];
        conv[edge[i][j]];
    }
    vi backconv;
    for(auto& a:conv) a.y=n++, backconv.pb(a.x);
    g.resize(n); 
    loop(i,0,k-1) {
        if (edge[i][0]>edge[i][1]) return cout<<-1<<endl,0;
        int a = conv[edge[i][0]],b=conv[edge[i][1]];
        g[a].pb({b,i}); g[b].pb({a,i});
    }
    if (!solve()) return cout<<-1<<endl,0;
    for(auto a:ans) cout<<backconv[a]<<" ";
    cout<<endl;  
    return 0;
}
/*
color a
cls
g++ NekoFlashback.cpp -o a & a
10
1 1 4 2 2 1 7 6 7
8 9 7 4 6 3 8 7 9




*/