#include<bits/stdc++.h>
using namespace std;

int a[200010],n,T,col[200010],b[200010];
char s[200010];

bool check()
{
	int bn=0;
	for (int i=1; i<=n; i++) if (col[i]==1) b[++bn]=a[i];
	for (int i=1; i<=n; i++) if (col[i]==2) b[++bn]=a[i];
	for (int i=1; i<n; i++) if (b[i]>b[i+1]) return 0;
	for (int i=1; i<=n; i++) putchar(col[i]+'0'); puts("");return 1;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n),scanf("%s",s);
		for (int i=0; i<n; i++) a[i+1]=s[i]-'0';
		for (int i=1; i<=n; i++) if (a[i]==0) col[i]=1; else col[i]=2;
		if (check()) continue;
		bool bo=0;
		for (int i=1,po; i<=9; i++)
		{
			po=0;
			for (int j=1; j<=n; j++) col[j]=2;
			for (int j=1; j<=n; j++) if (a[j]<i) col[j]=1,po=j;
			for (int j=po+1; j<=n; j++) if (a[j]==i) col[j]=1;
			if (check()) {bo=1; break;}
		}
		if (!bo) puts("-");
	}
	return 0;
}