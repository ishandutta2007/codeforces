#include<iostream>
#include<cstdio>
typedef long long ll;
const ll INF=1ll<<60;
#define maxn 100001
ll p[maxn];
struct one
{
	ll c,a;
	ll after,before;
	bool operator <(one b)
	{
		return c<b.c;
	}
}o[maxn],op[maxn];
ll n,m;
void Sort(ll l,ll r)// 
{
	if(l==r)return;
	ll mid=(l+r)>>1,i=l,j=mid+1,k=l;
	Sort(l,mid);Sort(mid+1,r);
	while(i<=mid&&j<=r)
	{
		if(o[i]<o[j])op[k++]=o[i++];
		else op[k++]=o[j++];
	}
	while(i<=mid)op[k++]=o[i++];
	while(j<=r)op[k++]=o[j++];
	for(ll w=l;w<=r;++w)o[w]=op[w];
}
ll min(ll a,ll b)
{
	return a<b?a:b;
}
int main()
{
	std::cin>>n>>m;
	for(ll i=1;i<=n;++i)std::cin>>o[i].a;
	for(ll i=1;i<=n;++i)
	{
		std::cin>>o[i].c;
		o[i].before=i;
	}
	Sort(1,n);
	for(ll i=1;i<=n;++i)p[o[i].before]=i;
	ll it=1,t,d,res;
	for(ll i=1;i<=m;++i)
	{
		std::cin>>t>>d;
		res=0;
		if(o[p[t]].a>=d)
		{
			o[p[t]].a-=d;
			res=d*o[p[t]].c;
			std::cout<<res<<"\n";
		}
		else
		{
			d-=o[p[t]].a;
			res+=o[p[t]].a*o[p[t]].c;
			o[p[t]].a=0;
			bool flag=0;
			while(1)
			{
				if(it>n)break;
				if(o[it].a>=d)
				{
					o[it].a-=d;
					res+=d*o[it].c;
					std::cout<<res<<"\n";
					flag=1;
					break;
				}
				else
				{
					d-=o[it].a;
					res+=o[it].a*o[it].c;
					o[it].a=0;
				}
				++it;
			}
			if(!flag)std::cout<<"0\n";
		}
	}
	return 0;
}