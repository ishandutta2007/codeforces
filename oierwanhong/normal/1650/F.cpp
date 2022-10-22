#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
typedef long long ll;
typedef std::pair<int,int> pii;
ll read()
{
	ll f=1,x=0;int c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
ll abs(ll x){return x>0?x:-x;}
template<typename T> inline bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
template<typename T> inline bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
/**********/
const int MAXN = 100011;
ll f[MAXN][211], a[MAXN],val[MAXN];
int pre[MAXN][211];
std::vector<int>res;
struct one{int v,w,dex;};
std::vector<one>b[MAXN];
int main()
{
	int task=read();
	while(task--)
	{
		res.clear();
		int n=read(),m=read();
		for(int i=1;i<=n;++i)a[i]=read(),b[i].clear();
		for(int i=1;i<=m;++i)
		{
			int e=read(),t=read(),p=read();
			b[e].emplace_back(one{t,p,i});
			val[i]=p;
		}
		ll now=0;
		bool fail=0;
		for(int x=1;x<=n;++x)
		{
			int L=b[x].size();
			memset(f[0],0x3f,sizeof f[0]);
			f[0][0]=0;
			for(int i=0;i<L;++i)
			{
				int v=b[x][i].v,w=b[x][i].w,dex=b[x][i].dex;
				memcpy(f[i+1],f[i],sizeof f[i+1]);
				memcpy(pre[i+1],pre[i],sizeof pre[i+1]);
				for(int j=0;j<100;++j)
					if(umin(f[i+1][j+w],f[i][j]+v))pre[i+1][j+w]=dex;
			}
			int minp=100;
			for(int j=100;j<200;++j)
				if(f[L][j]<f[L][minp])minp=j;
			now+=f[L][minp];
			if(now>a[x]){fail=1;break;}
			for(int i=L;i;--i)
			{
				if(pre[i][minp]==b[x][i-1].dex)
				{
					res.emplace_back(pre[i][minp]);
					minp-=val[pre[i][minp]];
				}
			}
		}
		if(fail){puts("-1");continue;}
		printf("%d\n",int(res.size()));
		for(auto x:res)printf("%d ",x);
		puts("");
	}
	return 0;
}