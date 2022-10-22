#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
typedef long long ll;
typedef std::pair<int,int> pii;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
void umax(int& a,int t){if(a<t)a=t;}
bool umin(ll& a,ll t){if(a>t)return a=t,1;return 0;}
ll abs(ll x){return x>0?x:-x;}

/**********/
pii a[5011];
bool check(int n)
{
	bool ok=0;
	for(int i=1;i<=n;++i)ok|=(a[i].first&1)|(a[i].second&1);
	return ok;
}
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)a[i].first=read(),a[i].second=read();
	for(int i=2;i<=n;++i)a[i].first-=a[1].first,a[i].second-=a[1].second;
	a[1]=pii(0,0);
	while(!check(n))
	{
		for(int i=1;i<=n;++i)a[i].first>>=1,a[i].second>>=1;
	}
	bool flag=0;
	for(int i=1;i<=n;++i)flag|=((a[i].first^a[i].second)&1);
	if(flag)
	{
		std::vector<int>res;
		for(int i=1;i<=n;++i)
			if(!((a[i].first^a[i].second)&1))res.push_back(i);
		printf("%d\n",int(res.size()));
		for(auto x:res)printf("%d ",x);
	}
	else
	{
		std::vector<int>res;
		for(int i=1;i<=n;++i)
			if(!(a[i].first&1))res.push_back(i);
		printf("%d\n",int(res.size()));
		for(auto x:res)printf("%d ",x);
	}
	return 0;
}