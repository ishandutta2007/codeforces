//Wan Hong 2.2
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
typedef long long ll;
typedef std::string str;
#define INF (1ll<<58)
ll read()
{
	char c;
	ll f=1,x=0;
	do
	{
		c=getchar();
		if(c=='-')f=-1;
	}while(c<'0'||c>'9');
	do
	{
		x=x*10+c-'0';
		c=getchar();
	}while(c>='0'&&c<='9');
	return f*x;
}
ll max(ll a,ll b)
{
	return a>b?a:b;
}
ll min(ll a,ll b)
{
    return a<b?a:b;
}

/**********/
#define MAXN 200011
ll ans[MAXN];
void work()
{
	ll n=read(),k=read(),sum=0,cnt=0;
	for(ll i=1;i<=n;++i)
	{
		sum+=read();
		if((sum&1)&&cnt<k-1)
		{
			ans[++cnt]=i;
			sum=0;
		}
	}
	if(cnt==k-1&&(sum&1))
	{
		puts("YES");
		for(ll i=1;i<k;++i)std::cout<<ans[i]<<" ";
		std::cout<<n<<std::endl;
	}
	else puts("NO");
}
int main()
{
	ll q=read();
	while(q--)work();
	return 0;
}