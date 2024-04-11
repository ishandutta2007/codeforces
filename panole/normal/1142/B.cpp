#include<bits/stdc++.h>
using namespace std;

int n,m,q,a[200010],po[200010],t[200010],f[200010][18],p[200010],lo[200010],l,r;

int jmp(int i,int j)
{
	for (int k=17; k>=0; k--)
		if (j>=(1<<k)) j-=(1<<k),i=f[i][k];
	return i;
}

int main()
{
	lo[1]=0;
	for (int i=2; i<=200000; i++) lo[i]=lo[i>>1]+1;
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]),po[a[i]]=i;
	a[n+1]=a[1];
	for (int i=1; i<=n; i++) t[i]=a[po[i]+1];
	for (int i=1; i<=m; i++) scanf("%d",&a[i]);
	for (int i=1; i<=n; i++) po[i]=m+1;
	for (int i=m; i; i--) f[i][0]=po[t[a[i]]],po[a[i]]=i;
	f[m+1][0]=m+1;
	for (int j=1; j<=17; j++)
		for (int i=1; i<=m+1; i++) f[i][j]=f[f[i][j-1]][j-1];
	for (int i=1; i<=m; i++) p[i]=jmp(i,n-1);
	for (int i=1; i<=m; i++) f[i][0]=p[i];
	for (int j=1; j<=17; j++)
		for (int i=1; i<=m; i++)
			if (i+(1<<j)-1<=m) f[i][j]=min(f[i][j-1],f[i+(1<<j-1)][j-1]);
	while (q--)
	{
		scanf("%d%d",&l,&r);
		int len=lo[r-l+1];
		if (min(f[l][len],f[r-(1<<len)+1][len])<=r) putchar('1'); else putchar('0');
	}
	return 0;
}