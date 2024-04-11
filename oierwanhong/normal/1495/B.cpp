#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
typedef long long ll;
typedef unsigned un;
typedef std::vector<int> P;
typedef std::pair<int,int> pii;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template <typename T> bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
template <typename T> bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
int abs(int x){return x>0?x:-x;}
/**********/
const int MAXN = 400011;
int preup[MAXN],predown[MAXN],sufup[MAXN],sufdown[MAXN];
int preg[MAXN],sufg[MAXN];
int a[MAXN];
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	preup[1]=predown[1]=1;
	for(int i=2;i<=n;++i)
		if(a[i-1]>a[i])preup[i]=preup[i-1],predown[i]=i;
		else predown[i]=predown[i-1],preup[i]=i;
	sufup[n]=sufdown[n]=n;
	for(int i=n-1;i;--i)
		if(a[i+1]>a[i])sufup[i]=sufup[i+1],sufdown[i]=i;
		else sufdown[i]=sufdown[i+1],sufup[i]=i;
	for(int i=1;i<=n;++i)preg[i]=max(preg[i-1],max(sufup[i]-i+1,i-preup[i]+1));
	for(int i=n;i;--i)sufg[i]=max(sufg[i+1],max(sufup[i]-i+1,i-preup[i]+1));

	int ans=0;
	for(int i=1;i<=n;++i)
	{
		bool flag=0;
		if(sufdown[i]>i)
		{
			int ed=sufdown[i],p;
			if((ed-i)&1)p=ed;
			else p=ed-1;
			if((i-predown[i])<=max(sufup[p]-p,p-preup[p]))flag=1;
			if(max(i-predown[i],sufdown[i]-i)<=(sufup[ed]-ed))flag=1;
		}
		if(predown[i]<i)
		{
			int ed=predown[i],p;
			if((i-ed)&1)p=ed;
			else p=ed+1;
			if((sufdown[i]-i)<=max(sufup[p]-p,p-preup[p]))flag=1;
			if(max(i-predown[i],sufdown[i]-i)<=(ed-preup[ed]))flag=1;
		}
		if(max(i-predown[i],sufdown[i]-i)+1<=max(preg[predown[i]-1],sufg[sufdown[i]+1]))flag=1;
		if(!flag)++ans;//,printf("%d\n",i);
	}
	printf("%d\n",ans);
	return 0;
}