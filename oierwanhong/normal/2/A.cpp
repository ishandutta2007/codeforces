#include<iostream>
#include<cstdio>
#include<map> 
#include<cstring>
typedef long long ll;
typedef std::string str;
const ll INF=1ll<<60;
std::map<str,ll>p,p2;
str t[1001],winer;
ll k[1001],ans;
int main()
{
	ll n;
	std::cin>>n;
	for(ll i=1;i<=n;++i)
	{
		std::cin>>t[i]>>k[i];
		p2[t[i]]=p2[t[i]]+k[i];
	}
	ans=p2[t[1]];
	for(ll i=2;i<=n;++i)
	{
		if(p2[t[i]]>ans)ans=p2[t[i]];
	}
	for(ll i=1;i<=n;++i)
	{
		p[t[i]]=p[t[i]]+k[i];
		if(p2[t[i]]==ans&&p[t[i]]>=ans)
		{
			winer=t[i];
			break;
		}
	}
	std::cout<<winer;
	return 0;
}