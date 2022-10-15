#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct slope_func 
{
	public:
	ll a,b;
	priority_queue<ll> bp;
	slope_func(ll aa, ll bb, vector<ll> v)
	{
		a=aa;
		b=bb;
		for (ll g : v) bp.push(g);
	}
	void slope_add (ll aa, ll bb, vector<ll> v)
	{
		a+=aa;
		b+=bb;
		for (ll g : v) bp.push(g);
	}	
	void slope_min()
	{
		while(a+bp.size()>0) bp.pop();
	}
};
ll n,m,i,j,k;
int main()
{
//	freopen("fractions.inp","r",stdin);
//	freopen("fractions.out","w",stdout);
	auto cur=slope_func(0,0,{});
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>m; m-=i;
		cur.slope_min();
		cur.slope_add(-1,m,{m,m});
	}	
	vector<ll> lis;
	while(cur.bp.size())
	{
		lis.push_back(cur.bp.top());
		cur.bp.pop();
	}
	m=cur.a;
	for (i=lis.size()-1;i>=0;i--)
	{
		if (m==0) break;
		if (i==lis.size()-1)
		{
			k=lis[i]*cur.a+cur.b;
		}
		else
		{
			k+=(lis[i]-lis[i+1])*m;
		}
		m++;
	}
	cout<<k<<endl;
}