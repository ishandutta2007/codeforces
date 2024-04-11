#include<cstdio>
#include<cstring>

int n,m,x;
bool b1[10],b2[10]; 

int main()
{
	scanf("%d%d",&n,&m);
	memset(b1,0,sizeof(b1));
	memset(b2,0,sizeof(b2));
	for (int i=1; i<=n; i++) scanf("%d",&x),b1[x]=1;
	for (int i=1; i<=m; i++) scanf("%d",&x),b2[x]=1;
	for (int i=0; i<=9; i++)
		if (b1[i]&&b2[i]) {printf("%d\n",i); return 0;}
	for (int i=1; i<=9; i++)
		if (b1[i])
		{
			for (int k=0; k<=9; k++)
				if (b2[k]) {printf("%d%d\n",i,k); return 0;}
		} else
		if (b2[i])
		{
			for (int k=0; k<=9; k++)
				if (b1[k]) {printf("%d%d\n",i,k); return 0;}
		}
	return 0;
}