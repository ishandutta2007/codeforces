#include<bits/stdc++.h>
using namespace std;

bool bo[1000010],Bo[1000010];
int n,m,a[1000010],q[1000010],l,r,cnt[2000010];
char s[1000010];

int calc(int x,int y) {return (x-1)*m+y;}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++)
	{
		scanf("%s",s);
		for (int j=1; j<=m; j++) a[calc(i,j)]=(s[j-1]=='#');
	}
	bo[calc(1,1)]=1,q[l=r=1]=calc(1,1);
	while (l<=r)
	{
		int x=q[l++];
		if (x+m<=n*m&&!bo[x+m]&&!a[x+m]) bo[x+m]=1,q[++r]=x+m;
		if (x%m!=0&&!bo[x+1]&&!a[x+1]) bo[x+1]=1,q[++r]=x+1;
	}
	Bo[calc(n,m)]=1,q[l=r=1]=calc(n,m);
	while (l<=r)
	{
		int x=q[l++];
		if (x-m>0&&!Bo[x-m]&&!a[x-m]) Bo[x-m]=1,q[++r]=x-m;
		if (x%m!=1&&!Bo[x-1]&&!a[x-1]) Bo[x-1]=1,q[++r]=x-1;
	}
	for (int i=1; i<=n; i++)
	for (int j=1; j<=m; j++)
		if (bo[calc(i,j)]&&Bo[calc(i,j)]) cnt[i+j]++;
	if (!Bo[1]) return puts("0"),0;
	for (int i=3; i<n+m; i++) if (cnt[i]==1) return puts("1"),0;
	puts("2");
	return 0;
}