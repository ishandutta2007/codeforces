//Wan Hong 2.2
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
typedef long long ll;
#define INF (1ll<<58)
ll read()
{
	ll x=0,f=1;
	char c;
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
ll min(ll a,ll b)
{
	return a<b?a:b;
}
ll max(ll a,ll b)
{
	return a>b?a:b;
}

/**********/
#define MAXN 211
char s[MAXN],t[MAXN],p[MAXN];
ll c[259];
void work()
{
	memset(c,0,sizeof c);
	std::cin>>s>>t>>p;
	for(ll i=strlen(p)-1;i>=0;--i)++c[p[i]];
	ll it=0,l=strlen(t);
	for(ll i=0;i<l;++i)
	{
		if(s[it]==t[i])++it;
		else
		{
			if(c[t[i]])--c[t[i]];
			else
			{
				puts("NO");
				return;
			}
		}
	}
	if(it==strlen(s))puts("YES");
	else puts("NO");
}
int main()
{
	ll q=read();
	while(q--)work();
	return 0;
}