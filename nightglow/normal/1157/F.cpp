#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<set>
#include<vector>
#include<map>
#include<queue>

#define N 300005
#define M 8000005

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define mk make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

int i,j,m,n,p,k,ans,ansx,ansy,a[N],vis[N];

int main()
{
		scanf("%d",&n);
		for (i=1;i<=n;++i) scanf("%d",&a[i]),vis[a[i]]++;
		for (i=1;i<=200000;)
		{
				if (vis[i]==0) ++i;
				else
				{
						for (j=i+1;j<=200000&&vis[j]>=2;++j);
						if (vis[j]==0) --j;
						int s=0;
						for (k=i;k<=j;++k) s+=vis[k];
						if (s>ans) ans=s,ansx=i,ansy=j; 
						if (vis[j]==1) i=max(i+1,j); else i=j+1;
				}
		}
		printf("%d\n",ans);
		for (i=1;i<=vis[ansx];++i) printf("%d ",ansx);
		for (i=ansx+1;i<ansy;++i)	
			for (j=1;j<vis[i];++j) printf("%d ",i);
		if (ansx!=ansy)
		for (i=1;i<=vis[ansy];++i) printf("%d ",ansy); 
		for (i=ansy-1;i>ansx;--i) printf("%d ",i);
}