#include<cstdio>
#include<cstring>

int ma,mi,n,k,a[100001];

int getmax(int a,int b) {return a>b?a:b;}
int getmin(int a,int b) {return a<b?a:b;}

int main()
{
	scanf("%d%d",&n,&k); ma=-(2e9); mi=2e9;
	for (int i=1; i<=n; i++) scanf("%d",&a[i]),ma=getmax(ma,a[i]),mi=getmin(mi,a[i]);
	if (k==1) printf("%d\n",mi); else
	if (k==2) printf("%d\n",getmax(a[1],a[n])); else printf("%d\n",ma);
	return 0;
}