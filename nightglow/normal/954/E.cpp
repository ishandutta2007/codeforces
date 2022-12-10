#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 300005

using namespace std;

int a[N],t[N],i,j,m,n,p,k,id[N],ID[N],sum[N],T;

double ans;

int cmp(int x,int y)
{
		return sum[x]<sum[y];
}

int main()
{
		scanf("%d%d",&n,&T);
		for (i=1;i<=n;++i) 
		{
				scanf("%d",&a[i]);
		}
		for (i=1;i<=n;++i) scanf("%d",&t[i]);
		for (i=1;i<=n;++i)
		{
				if (t[i]==T) ans+=a[i];
				else if (t[i]<T) id[++id[0]]=i,sum[i]=T-t[i];
				else ID[++ID[0]]=i,sum[i]=t[i]-T;
		}
		sort(id+1,id+id[0]+1,cmp);
		sort(ID+1,ID+ID[0]+1,cmp);
		long long suma=0,sumb=0;
		for (i=1;i<=id[0];++i)
			suma+=1ll*sum[id[i]]*a[id[i]];
		for (i=1;i<=ID[0];++i)
			sumb+=1ll*sum[ID[i]]*a[ID[i]];
		if (suma<sumb)
		{
				swap(suma,sumb);
				for (i=0;i<=n;++i) swap(ID[i],id[i]);
		}
		for (i=1;i<=ID[0];++i) ans+=a[ID[i]];
		for (i=1;i<=id[0];++i)
			if (1ll*sum[id[i]]*a[id[i]]>=sumb)
			{
					ans+=1.*sumb/sum[id[i]];
					break;
			}
			else
			{
					ans+=a[id[i]];
					sumb-=1ll*sum[id[i]]*a[id[i]];
			}
		printf("%.10lf\n",ans);
}