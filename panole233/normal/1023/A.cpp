#include<cstdio>
#include<cstring>

char s[300001],t[300001];
int n,m;
bool bo;

int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",s+1); scanf("%s",t+1);
	for (int i=1; i<=n; i++)
		if (s[i]=='*')
		{
			if (m<n-1) {printf("NO\n"); return 0;}
			bo=1;
			for (int j=1; j<i; j++)
				if (s[j]!=t[j]) {bo=0; break;}
			for (int j=n; j>i; j--)
				if (s[j]!=t[m-(n-j)]) {bo=0; break;}
			if (!bo) printf("NO\n"); else printf("YES\n");
			return 0;
		}
	if (m!=n) {printf("NO\n"); return 0;}
	for (int i=1; i<=n; i++) if (s[i]!=t[i]) {printf("NO\n"); return 0;}
	printf("YES\n");
	return 0;
}