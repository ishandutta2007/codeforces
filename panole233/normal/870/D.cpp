#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

int T,n,ans[5001][2],s,f[5001][5001],anss[5001];
bool b;

int main()
{
	scanf("%d",&n); anss[1]=-1; s=0;
	for (int i=0; i<n; i++) printf("? 0 %d\n",i),fflush(stdout),scanf("%d",&f[1][i+1]);
	for (int i=0; i<n; i++) printf("? %d 0\n",i),fflush(stdout),scanf("%d",&f[i+1][1]);
	for (int i=2; i<=n; i++)
		for (int j=2; j<=n; j++)
			f[i][j]=(f[i][1]^f[1][1]^f[1][j]);
	for (int i=0; i<n; i++)
	{
		ans[1][0]=i; b=1;
		for (int j=1; j<=n; j++) 
			if ((ans[1][0]^f[1][j])<5000) ans[j][1]=ans[1][0]^f[1][j];
			else {b=0; break;}
		if (!b) continue;
		for (int j=1; j<=n; j++) 
			if ((ans[1][1]^f[j][1])<5000) ans[j][0]=ans[1][1]^f[j][1];
			else {b=0; break;}
		if (!b) continue;
		for (int j=1; j<=n; j++)
			if (ans[ans[j][0]+1][1]+1!=j) {b=0; break;}
		if (b)
		{
			s++;
			if (anss[1]==-1)
				for (int j=1; j<=n; j++) anss[j]=ans[j][0];
		}
	}
	printf("!\n%d\n",s);
	for (int i=1; i<=n; i++) printf("%d ",anss[i]);
	fflush(stdout);
	return 0;
}