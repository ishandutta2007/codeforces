#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long ll;
typedef unsigned un;
typedef unsigned long long ull;
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
const int MAXN = 200011;
char a[MAXN];
int loc[MAXN];
int main()
{
	int task=read();
	while(task--)
	{
		int n=read(),ans=-1;
		scanf("%s",a+1);
		for(char c='a';c<='z';++c)
		{
			int len=0,fail=0;
			for(int i=1;i<=n;++i)
				if(a[i]!=c)loc[++len]=i;
			loc[len+1]=n+1;
			for(int i=1;i<=(len>>1);++i)
				if(a[loc[i]]!=a[loc[len-i+1]])fail=1;
			if(fail)continue;
			int cur= !(len&1)?loc[(len>>1)+1]-loc[len>>1]-1:0;
			for(int i=1;i<=((len+1)>>1);++i)cur+=2*min(loc[i]-loc[i-1]-1,loc[len-i+2]-loc[len-i+1]-1);
			umax(ans,cur+len);
		}
		printf("%d\n",ans>=0?n-ans:-1);
	}
	return 0;
}