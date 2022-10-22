#include <bits/stdc++.h>
#define int int64_t
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ii pair<int,int>
#define x first
#define y second
#define abs(x) ((x>0)?(x):(-x))
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define ii pair<int,int>
using namespace std;
const int MOD=1e9+7ll;
struct DSU
{
	vi par;
	int sz;
	DSU() {}
	DSU(int n)
	{
		par.resize(n, -1);
		sz = n;
	}
	int find(int x)
	{
		if (par[x] == -1) return x;
		return par[x] = find(par[x]);
	}
	void uni(int x, int y)
	{
        x = find(x); y = find(y);
        if ((x != -1 || y != -1) && x == y) return;
        sz--;
        par[y] = x;
	}
};
vector<vi> g;
vi sign;
bool pos=true;
int dfs(int cur,int s){
    if(sign[cur]!=-1) {
        return 0;
    }
    sign[cur]=s;
    for(auto nei:g[cur]){
        if(sign[nei]==-1) dfs(nei,1-s);
        else if (sign[nei]==s) pos=false;
    }
    return 1;
}
int power(int b, int e)
{
	if (e == 0) return 1;
	if (e == 1) return b;
	int val = power(b, e / 2);
	return (val*val*(e % 2 ? b : 1)) % MOD;
}
int32_t main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n,m;cin>>n>>m;
    int a,b,c;
    vector<ii> edge;
    DSU d(n);
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;a--;b--;
        if(c==1) d.uni(a,b);
        else edge.pb(mp(a,b));
    }
    int cnt=0;
    vi conv(n);
    for(int i=0;i<n;i++){
        if (d.par[i]==-1) conv[i]=cnt++;
    }
    g.resize(cnt);
    sign.resize(cnt,-1);
    for(int i=0;i<edge.size();i++){
        a=conv[d.find(edge[i].x)],b=conv[d.find(edge[i].y)];
        if (a==b) pos=false;
        g[a].pb(b);
        g[b].pb(a);
    }
    int sum=0;
    for(int i=0;i<cnt;i++) sum+=dfs(i,0);
    //cout << sum<<endl;
    if(pos) cout<<power(2,sum-1)<<endl;
    else cout<<0<<endl;
    return 0;
}