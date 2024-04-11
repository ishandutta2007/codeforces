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
char s[500011];
int main()
{
	int task=read();
	while(task--)
	{
		scanf("%s",s+1);
		int n=strlen(s+1),diff=0;
		for(int i=1;i<=n;++i)
			if(s[i]!=s[i-1])++diff;
		if(diff>3)puts("2");
		else if(diff==3)puts(s[1]=='0'?"2":"1");
		else if(diff==2)puts("1");
		else puts(s[1]=='0'?"1":"0");
	}
	return 0;
}