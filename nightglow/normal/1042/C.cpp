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

int i,j,m,n,p,k,a[N],zh[N],zr[N],fu[N];

int cmp(int x,int y)
{
		return a[x]<a[y];
}

int main()
{
	 scanf("%d",&n);
	 for (i=1;i<=n;++i)
	 {
	 		scanf("%d",&a[i]);
	 		if (a[i]>0) zh[++zh[0]]=i;
	 		else if (a[i]==0) zr[++zr[0]]=i;
	 		else fu[++fu[0]]=i;
	 }
	 sort(fu+1,fu+fu[0]+1,cmp);
	 if (zh[0]>0)
	 {
	 		for (i=2;i<=zh[0];++i) printf("1 %d %d\n",zh[i],zh[1]);
	 		for (i=1;i<fu[0];i+=2)
	 		{
	 				printf("1 %d %d\n",fu[i],zh[1]);
	 				printf("1 %d %d\n",fu[i+1],zh[1]);
	 		}
	 		if (fu[0]&1)
	 		{
	 				int g=fu[fu[0]];
	 				for (i=1;i<=zr[0];++i) printf("1 %d %d\n",zr[i],g);
	 				printf("2 %d\n",g);
	 		}
	 		else if (zr[0])
	 		{
	 				for (i=2;i<=zr[0];++i) printf("1 %d %d\n",zr[i],zr[1]);
	 				printf("2 %d\n",zr[1]);
	 		}
	 }
	 else
	 {
	 		if (fu[0]>1)
	 		{
	 			for (i=1;i<fu[0];i+=2)
				{
						if (i>1) printf("1 %d %d\n",fu[i],fu[1]);
						printf("1 %d %d\n",fu[i+1],fu[1]); 
				}
	 			if (fu[0]&1)
	 			{
	 				int g=fu[fu[0]];
	 				for (i=1;i<=zr[0];++i) printf("1 %d %d\n",zr[i],g);
	 				printf("2 %d\n",g);
	 			}
	 			else if (zr[0])
	 			{
	 				for (i=2;i<=zr[0];++i) printf("1 %d %d\n",zr[i],zr[1]);
	 				printf("2 %d\n",zr[1]);
	 			}	 				
	 		}
	 		else
	 		{
	 					for (i=2;i<=n;++i) printf("1 %d %d\n",i,1);
	 		}
	 }
}