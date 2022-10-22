#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
typedef long long ll;
ll read()
{
	ll f=1,x=0;int c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template<typename T> inline bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
template<typename T> inline bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
/**********/
const int MAXN = 400011,INF = 1e9+233;
char a[MAXN],b[MAXN];
int main()
{
	int task=read();
	while(task--)
	{
		int n=read();
		scanf("%s%s",a+1,b+1);
		int ans=INF,f1=0,f2=0,f3=0,bal=0,cb=0;
		for(int i=1;i<=n;++i)
			if(a[i]=='1')++bal;
			else --bal;
		for(int i=1;i<=n;++i)
			if(b[i]=='1')++cb;
			else --cb;
		for(int i=1;i<=n;++i)f1+= a[i]!=b[i];
		if(bal==cb)umin(ans,f1);
		// (1,0)
		int p=0;
		for(int i=1;i<=n;++i)
			if(a[i]=='1'&&b[i]=='0'){p=i;break;}
		if(p)
		{
			bal=0;
			for(int i=1;i<=n;++i)
			{
				char ch= i==p||a[i]=='0'?'1':'0';
				bal+= ch=='1'?1:-1;
				f2+= ch!=b[i];
			}
			if(bal==cb)umin(ans,f2+1);
		}
		// (1,1)
		p=0;
		for(int i=1;i<=n;++i)
			if(a[i]=='1'&&b[i]=='1'){p=i;break;}
		if(p)
		{
			bal=0;
			for(int i=1;i<=n;++i)
			{
				char ch= i==p||a[i]=='0'?'1':'0';
				bal+= ch=='1'?1:-1;
				f3+= ch!=b[i];
			}
			if(bal==cb)umin(ans,f3+1);
		}
		if(ans==INF)puts("-1");
		else printf("%d\n",ans);
	}
	return 0;
}