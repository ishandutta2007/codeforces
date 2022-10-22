#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long ll;
typedef std::pair<int,int> pii;
ll read()
{
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
/**********/
char a[511];
int main()
{
	int n=read(),cur=0;
	while(n--)
	{
		int x=read();
		scanf("%s",a+1);
		if(a[1]=='E'||a[1]=='W')
		{
			if(cur==0||cur==20000){puts("NO");return 0;}
			continue;
		}
		if(a[1]=='N')
		{
			cur-=x;
			if(cur<0){puts("NO");return 0;}
		}
		else
		{
			cur+=x;
			if(cur>20000){puts("NO");return 0;}
		}
	}
	puts(cur==0?"YES":"NO");
	return 0;
}