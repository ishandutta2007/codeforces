#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
struct one
{
	ll v,dex;
	bool operator <(const one &to)const
	{
		return v<to.v;
	}
}p[1000001];
ll out[1000001];
ll ans=0,n,sum=0;
void fir()
{
	cin>>n;
	for(ll i=1;i<=n;++i)
	{
		cin>>p[i].v;
		p[i].dex=i;
	}
}
void MY_find(ll key)
{
	for(ll i=1;i<n;i++)
	{
		if(p[i].v==key)out[++ans]=p[i].dex;
	}
}
void end()
{
	cout<<ans<<endl;
	for(ll i=1;i<=ans;i++)cout<<out[i]<<" ";
}
int main()
{
	fir();
	
	sort(p+1,p+n+1);
	
	for(ll i=1;i<n;i++)
	{
		sum+=p[i].v;
	}
	MY_find(sum-p[n].v);
	if(sum-p[n-1].v==p[n-1].v)out[++ans]=p[n].dex;
	
	end();
	
	return 0;
}