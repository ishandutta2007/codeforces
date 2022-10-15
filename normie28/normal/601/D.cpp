#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
    seed_seq seq{
        (uint64_t) chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count(),
        (uint64_t) __builtin_ia32_rdtsc(),
        (uint64_t) (uintptr_t) make_unique<char>().get()
    };
    mt19937 rng(seq);
    int p,base;
    int prime(ll x)
    {
    	if (x<2) return 0;
    	for (int i=2;i<=sqrt(x);i++) if (x%i==0) return 0;
    	return 1;
    }
ll get_rand(ll l, ll r)
{
	return uniform_int_distribution<ll>(l,r)(rng);
}
ll get_p()
{
	ll res;
	while(true)
	{
		res=get_rand(1e9,2e9);
		if (prime(res)) return res;
	}
}
ll bow (ll a, ll x, ll p)
{
	if (!x) return 1;
    ll res=bow(a,x/2,p);
    res*=res;
    res%=p;
    if (x%2) res*=a;
    res%=p;
    return res;
}
ll pr,ba,pr2,ba2;
ll n,m,i,j,k,t,t1,u,v,a,b;
string s;
ll val[300001],val2[300001],c[300001];
vector<ll> gt[300001],gtd[300001];
set<ll> buc[300001];
void dfs(ll x)
{
	for (ll g : gt[x]) if (val[g]==-1)
	{
		gtd[x].push_back(g);
		val[g]=val[x]*ba;
		val[g]%=pr;
		val[g]+=s[g-1]-96;
		val[g]%=pr;
		val2[g]=val2[x]*ba2;
		val2[g]%=pr2;
		val2[g]+=s[g-1]-96;
		val2[g]%=pr2;
		dfs(g);
	}
}
ll calc(ll x)
{
	if (gtd[x].size()==0)
	{
		c[x]++;
		buc[x]={val[x]*3000000000+val2[x]};
		return x;
	}
	else
	{
		vector<ll> cand;
		for (ll g : gtd[x])
		{
			cand.push_back(calc(g));
		}
		sort(cand.begin(),cand.end(),[](ll a, ll b) {
			return (buc[a].size()>buc[b].size());
		});
		for (ll i=1;i<cand.size();i++)
		{
			for (ll g: buc[cand[i]])
			buc[cand[0]].insert(g);
			buc[cand[i]].clear();
		}
		buc[cand[0]].insert(val[x]*3000000000+val2[x]);
		c[x]+=buc[cand[0]].size();
		return cand[0];
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	pr=get_p();
	ba=get_rand(27,pr-1);
	pr2=get_p();
	ba2=get_rand(27,pr2-1);
	cin>>n;
	for (i=1;i<=n;i++) cin>>c[i];
	cin>>s;
	for (i=1;i<n;i++)
	{
		cin>>u>>v;
		gt[u].push_back(v);
		gt[v].push_back(u);
	}
	for (i=1;i<=n;i++) val[i]=-1;
	val[1]=s[0]-96;
	val2[1]=s[0]-96;
	dfs(1);
	calc(1);
	u=0;
	v=0;
	for (i=1;i<=n;i++) if (c[i]>u)
	{
		u=c[i];
		v=1;
	}
	else if (c[i]==u) v++;
	cout<<u<<endl<<v;
}