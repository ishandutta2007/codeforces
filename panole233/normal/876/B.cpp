#include<cstdio>
#include<cstring>

int n,m,k,a[200001],b[200001],ans;

int main()
{
	scanf("%d%d%d",&n,&k,&m);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]),b[a[i]%m]++;
	bool bo=0;
	for (int i=0; i<m; i++)
		if (b[i]>=k) {printf("Yes\n"); bo=1; ans=i; break;}
	if (!bo) {printf("No\n"); return 0;}
	int tot=0;
	for (int i=1; i<=n; i++)
	{
		if (a[i]%m==ans) printf("%d ",a[i]),++tot;
		if (tot==k) return 0;
	}
	return 0;
}