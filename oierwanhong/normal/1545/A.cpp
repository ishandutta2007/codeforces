#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
typedef long long ll;
typedef unsigned un;
typedef std::vector<int> P;
typedef std::pair<int,int> pii;
typedef std::string str;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template <typename T> bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
template <typename T> bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
/**********/

const int MAXN = 1000011;
int a[MAXN],b[MAXN];
int odd[MAXN],even[MAXN];
int main()
{
	int task=read();
	while(task--)
	{
		int n=read();
		for(int i=1;i<=n;++i)b[i]=a[i]=read(),odd[b[i]]=even[b[i]]=0;
		std::sort(b+1,b+n+1);
		for(int i=1;i<=n;++i)
			if(i&1)++odd[b[i]];
			else ++even[b[i]];
		bool fail=0;
		for(int i=1;i<=n;++i)
		{
			if(i&1)
			{
				if(!odd[a[i]])fail=1;
				else --odd[a[i]];
			}
			else
			{
				if(!even[a[i]])fail=1;
				else --even[a[i]];
			}
		}
		puts(fail?"NO":"YES");
	}
	return 0;
}