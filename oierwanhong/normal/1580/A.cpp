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
char a[411][411];
int sum[411][411],lst[21], ans;
void update(){}
int Query(int x1,int y1,int x2,int y2){return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];}
int main()
{
	int task=read();
	while(task--)
	{
		int n=read(),m=read();
		for(int i=1;i<=n;++i)scanf("%s",a[i]+1);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(a[i][j]=='1'),
		ans=16;
		for(int s=1;s<=m;++s)
			for(int t=s+3;t<=m;++t)
			{
				memset(lst,0,sizeof lst);
				for(int r=n-4;r;--r)
				{
					int tp=(t-s-1)-Query(r+4,s+1,r+4,t-1);
					if(tp<ans)lst[tp]=r+4;
					int cur=(t-s-1)-Query(r,s+1,r,t-1);
					for(int i=0;i+cur<ans;++i)
						if(lst[i])
						{
							int white= sum[lst[i]-1][t-1]-sum[lst[i]-1][s]-sum[r][t-1]+sum[r][s];
							if(i+cur+white>ans)continue;
							umin(ans,cur+i+white+(lst[i]-r-1)*2-Query(r+1,s,lst[i]-1,s)-Query(r+1,t,lst[i]-1,t));
						}
				}
			}
		printf("%d\n",ans);
	}
	return 0;
}