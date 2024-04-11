#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
typedef long long ll;
typedef std::vector<int> P;
typedef std::pair<int,int> pii;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template <typename T> bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
template <typename T> bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
/**********/
const int MAXN = 500011;
std::vector<int>a[MAXN];
int ord[MAXN],f[MAXN],res[MAXN];
bool cmp(int x,int y){return a[x].size()<a[y].size();}
int main()
{
	int task=read();
	while(task--)
	{
		int n=read(),m=read(),lim=(m+1)>>1;
		for(int i=1;i<=n;++i)f[i]=0;
		for(int i=1;i<=m;++i)
		{
			a[i].clear();
			ord[i]=i;
			int k=read();
			while(k--)a[i].push_back(read());
		}
		std::sort(ord+1,ord+m+1,cmp);
		bool fail=0;
		for(int i=1;i<=m;++i)
		{
			int x=ord[i],minv=1e9,loc=0;
			for(auto k:a[x])
				if(f[k]<minv)minv=f[k],loc=k;
			if(f[loc]==lim){fail=1;break;}
			++f[loc],res[x]=loc;
		}
		if(fail){puts("NO");continue;}
		puts("YES");
		for(int i=1;i<=m;++i)printf("%d ",res[i]);
		puts("");
	}
	return 0;
}