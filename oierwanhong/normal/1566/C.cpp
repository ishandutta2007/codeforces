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
char a[500011],b[500011];
int main()
{
	int task=read();
	while(task--)
	{
		int n=read(),ans=0;
		scanf("%s%s",a+1,b+1);
		for(int i=1;i<=n;++i)
			if(a[i]!=b[i])ans+=2;
			else if(a[i]=='0')
			{
				if(a[i-1]=='1'&&b[i-1]=='1')ans+=2;
				else if(a[i+1]=='1'&&b[i+1]=='1')ans+=2,a[i+1]='0',++i;
				else ++ans;
			}
		printf("%d\n",ans);
	}
	return 0;
}