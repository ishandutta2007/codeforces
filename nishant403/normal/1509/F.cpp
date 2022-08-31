#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}
  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

const int MOD = 1e9+7;

int mod_pow(int a,int b,int M = MOD)
{
    if(a == 0) return 0;
    b %= (M - 1);  //M must be prime here
    
    int res = 1;
    
    while(b > 0)
    {
        if(b&1) res=(res*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    
    return res;
}

const int N = 2e5 + 10;

struct DSU
{
	int connected;
	int par[N], sz[N];

	DSU() {} 

	DSU(int n) 
	{
		for(int i=1;i<=n;i++)
		{
			par[i]=i;
			sz[i]=1;
		}
		connected=n;
	}

	int getPar(int k)
	{
		while(k!=par[k])
		{
			par[k]=par[par[k]];
			k=par[k];
		}
		return k;
	}

	int getSize(int k)
	{
		return sz[getPar(k)];
	}

	void unite(int u, int v)
	{
		int par1=getPar(u), par2=getPar(v);

		if(par1==par2)
			return;

		connected--;

		if(sz[par1]>sz[par2])
			swap(par1, par2);

		sz[par2]+=sz[par1];
		sz[par1]=0;
		par[par1]=par[par2];
	}
};

vector<pii> g[N];

DSU inv(N);

unordered_map<int,int> g2[N];
    
vector<vi> cmp;

int red[N];

void reduce(vector<int> go)
{
    if(go.empty()) return;
    
    int id = go[0];
    
    for(int i=0;i<go.size();i++)
    {
        if(g2[go[i]].size() < g2[id].size())
        {
            id = go[i];
        }
    }
    
    set<int> vert;
    
    for(auto x : go) if(x != id) vert.insert(x);
        
    vi cc;
    cc.pb(id);
        
    int ss = 1;
    
    
    for(int i=0;i<ss;i++)
    {
        vi mm;
        
        for(auto x : vert)
        {
            if(g2[cc[i]].find(x) == g2[cc[i]].end())
            {
                mm.pb(x);
                ss++;
            }
        }
        
        for(auto x : mm) cc.pb(x);
        for(auto x : mm) vert.erase(x);
    }
    
    cmp.pb(cc);
    
    for(auto x : cc) red[x] = 1;
    for(auto x : cc) inv.unite(x , cc[0]);
    
    vector<int> cc2;
    
    for(auto x : go)
        if(red[x] == 0) cc2.pb(x);
    
    reduce(cc2);
}


multiset<pair<int,pii> > rrr;

DSU mst2(N);

DSU mst3(N);

int mst(vector<pair<pair<int,pii>,pii> > ed)
{
    sort(all(ed));
    
    int res = 0;
    
    for(auto x : ed)
    {
        if(mst2.getPar(x.F.S.F) == mst2.getPar(x.F.S.S)) continue;
        res += x.F.F;
        mst2.unite(x.F.S.F,x.F.S.S);
        mst3.unite(x.S.F,x.S.S);
    }
    
    return res;
}

int vis2[N];

int ee(vector<int> & ss)
{
    int sz = (int)ss.size();
    
    int tot_ed = (sz*(sz - 1))/2;
    
    for(auto x : ss)
    {
        for(auto y : g[x])
        {
             if(vis2[y.F]) tot_ed--;
        }
        
        vis2[x] = 1;
    }
    
    for(auto x : ss) vis2[x] = 0;
    
    assert(tot_ed >= sz - 1);
    
    return (tot_ed >= sz);
}


void solve()
{
    int n,m;
    cin >> n >> m;
    
    int u,v,w;
    
    int xr = 0;
    
    f(i,m)
    {
        cin >> u >> v >> w;
        
        xr^=w;
        
        g[u].pb({v,w});
        g[v].pb({u,w});
        
        rrr.insert({w,{u,v}});
        rrr.insert({w,{v,u}});
        
        g2[u][v] = g2[v][u] = w;
    }
    
    vector<int> tmp;
    for(int i=1;i<=n;i++) tmp.pb(i);
    
    reduce(tmp);
    
    vector<pair<pair<int,pii>,pii> > ed;
    
    //first build the required mst between two different components
    for(int i=1;i<=n;i++)
    {
        for(auto x : g[i])
        {
            ed.pb({{x.S,{inv.getPar(x.F),inv.getPar(i)}},{x.F,i}});
        }
    }
    
    int res = mst(ed);
    
    int sz = (cmp.size());
    
    if(sz == n)
    {
        cout << res;
        return;
    }
    
    for(auto x : cmp)
    {
        if(ee(x) == 1)
        {
            cout << res;
            return;
        }
    }
    
    while(!rrr.empty())
    {
        auto z = *rrr.begin();
        
        if(mst3.getPar(z.S.F) == mst3.getPar(z.S.S))
        {
            rrr.erase(rrr.begin());
        }
        else  break;
    }
    
    if(!rrr.empty()) xr = min(xr,(*rrr.begin()).F);
    
    cout << res + xr;
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}