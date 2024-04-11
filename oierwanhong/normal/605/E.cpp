#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<random>
#include<chrono>
typedef long long ll;
typedef unsigned un;
typedef std::vector<int> P;
typedef std::pair<int,int> pii;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template <typename T> bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
template <typename T> bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
/**********/
const int MAXN = 1011;
double a[MAXN][MAXN],f[MAXN],p[MAXN];
bool used[MAXN];
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)a[i][j]=read()/100.0;
	for(int i=1;i<n;++i)f[i]=1e18,p[i]=1;
	f[n]=0;
	for(int T=1;T<=n;++T)
	{
		int s=-1;
		for(int u=1;u<=n;++u)
			if(!used[u]&&(s==-1||f[u]<f[s]))s=u;
		if(s==-1){std::cerr<<"ERR!!"<<std::endl;return 0;}
		used[s]=1;
		for(int u=1;u<=n;++u)
			if(!used[u])
			{
				if(f[u]>5e17)
				{
					p[u]=(1-a[u][s]),f[u]=(1+a[u][s]*f[s])/(1-p[u]);
					continue;
				}
				double tp=f[u]*(1-p[u])+p[u]*a[u][s]*f[s];
				p[u]=p[u]*(1-a[u][s]),f[u]=tp/(1-p[u]);
			}
	}
	printf("%.7lf\n",f[1]);
	return 0;
}