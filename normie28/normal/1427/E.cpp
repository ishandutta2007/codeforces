#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct op
{
	char typ;
	ll a,b;
	op(char _typ, ll _a, ll _b)
	{
		typ=_typ;
		a=_a;
		b=_b;
	}
};
ll get_rand(ll l, ll r)
{
	ll aa=(rand()<<15)^(rand());
	return aa%(r-l+1)+l;
}
vector<op> res,cur;
ll n,m,i,j,k,t,t1,u,v,a,b;
vector<ll> base;
int main()
{
	srand(time(NULL));
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	base.push_back(n);
	for (t=1;t<=200000;t++)
	{
	//	cout<<t<<' '<<base.size()<<endl;
		cur.clear();
		sort(base.begin(),base.end());
		if (base[0]==1) break;
		u=get_rand(0,base.size()-1);
		v=get_rand(0,base.size()-1);
		u=base[u];
		v=base[v];
		cur.emplace_back('+',u,v);
		u+=v;
		if (u>=(ll)1<<58) continue;
		for (i=base.size()-1;i>=0;i--)
		{
			if (floor(log2(u))==floor(log2(base[i])))
			{
				cur.emplace_back('^',u,base[i]);
				u^=base[i];
			}
		}
		if (u)
		{
			for (auto g : cur) res.push_back(g);
			base.push_back(u);
		}
	}
	for (t=1;t<=200000;t++)
	{
		cur.clear();
		sort(base.begin(),base.end());
		if (base[0]==1) break;
		u=get_rand(0,base.size()-1);
		v=get_rand(0,base.size()-1);
		u=base[u];
		v=base[v];
		cur.emplace_back('^',u,v);
		u^=v;
		if (u>=(ll)1<<58) continue;
		for (i=base.size()-1;i>=0;i--)
		{
			if (floor(log2(u))==floor(log2(base[i])))
			{
				cur.emplace_back('^',u,base[i]);
				u^=base[i];
			}
		}
		if (u)
		{
			for (auto g : cur) res.push_back(g);
			base.push_back(u);
		}
	}
	cout<<res.size()<<endl;
	for (auto g : res) cout<<g.a<<' '<<g.typ<<' '<<g.b<<endl;
}