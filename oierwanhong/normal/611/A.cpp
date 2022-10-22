#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long ll;
typedef std::pair<int,int> pii;
int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
/**********/

char s[511];
int main()
{
	int x=read();
	scanf("%s",s+1);scanf("%s",s+1);
	if(s[1]=='w')
	{
		printf("%d\n",x==5||x==6?53:52);
	}
	else
	{
		if(x<=29)puts("12");
		else if(x==30)puts("11");
		else if(x==31)puts("7");
	}
	return 0;
}