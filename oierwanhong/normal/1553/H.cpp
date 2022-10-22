#include<cstdio>
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}

const int L = 1<<19;
int fi[L],fx[L];
int ans[L];
void powerful_FWT()
{
	for(int cur=1;cur<L;cur<<=1)
		for(int j=0;j<L;j+=cur<<1)
			for(int k=0;k<cur;++k)
			{
				int x=j+k,y=j+cur+k;
				int tp=min(ans[x],ans[y]);
				ans[x]=min(tp,fi[y]+cur-fx[x]),ans[y]=min(tp,fi[x]+cur-fx[y]);
				int nx=min(fi[x],fi[y]+cur),ny=min(fi[y],fi[x]+cur);
				fi[x]=nx,fi[y]=ny;
				nx=max(fx[x],fx[y]+cur),ny=max(fx[y],fx[x]+cur);
				fx[x]=nx,fx[y]=ny;
			}
}
int main()
{
	int n,k;scanf("%d%d",&n,&k);
	for(int s=0;s<L;++s)fi[s]=ans[s]=L,fx[s]=-L;
	for(int i=1;i<=n;++i)
	{
		int x;scanf("%d",&x);
		fi[x]=fx[x]=0;
	}
	powerful_FWT();
	for(int s=0;s<(1<<k);++s)printf("%d ",ans[s]);
	return 0;
}