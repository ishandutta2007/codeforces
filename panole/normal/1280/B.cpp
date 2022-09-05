#include<bits/stdc++.h>
using namespace std;

int n,T,m;
char s[110][110];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		bool boA=1,boP=1;
		scanf("%d%d",&n,&m);
		for (int i=1; i<=n; i++) 
		{
			scanf("%s",s[i]+1);
			for (int j=1; j<=m; j++)
				if (s[i][j]=='A') boP=0; else boA=0;
		}
		if (boA) {puts("0"); continue;}
		if (boP) {puts("MORTAL"); continue;}
		bool bo=1;
		for (int i=1; i<=m; i++) if (s[1][i]=='P') bo=0;
		if (bo) {puts("1"); continue;}
		bo=1;
		for (int i=1; i<=m; i++) if (s[n][i]=='P') bo=0;
		if (bo) {puts("1"); continue;}
		bo=1;
		for (int i=1; i<=n; i++) if (s[i][1]=='P') bo=0;
		if (bo) {puts("1"); continue;}
		bo=1;
		for (int i=1; i<=n; i++) if (s[i][m]=='P') bo=0;
		if (bo) {puts("1"); continue;}
		if (s[1][1]=='A'||s[1][m]=='A'||s[n][1]=='A'||s[n][m]=='A') {puts("2"); continue;}
		bool boo=0;
		for (int i=1; i<=n; i++)
		{
			bo=1;
			for (int j=1; j<=m; j++) if (s[i][j]=='P') bo=0;
			if (bo) {boo=1; break;}
		}
		for (int j=1; j<=m; j++)
		{
			bo=1;
			for (int i=1 ;i<=n; i++) if (s[i][j]=='P') bo=0;
			if (bo) {boo=1; break;}
		}
		if (boo) {puts("2"); continue;}
 		bo=0;
		for (int i=1; i<=n; i++)
			if (s[i][1]=='A'||s[i][m]=='A') bo=1;
		for (int i=1; i<=m; i++)
			if (s[1][i]=='A'||s[n][i]=='A') bo=1;
		if (bo) puts("3"); else puts("4");
	}
	return 0;
}