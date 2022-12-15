#include<cstdio>
#include<cstring>

const int inf=1050000000;
int n,f[8],x,y;
char s[11];

int main()
{
	scanf("%d",&n); 
	for (int i=0; i<8; i++) f[i]=inf; f[0]=0;
	for (int i=1; i<=n; i++)
	{
		scanf("%d",&x); scanf("%s",s); y=0;
		for (int j=0; j<strlen(s); j++)
			if (s[j]=='A') y|=1; else
			if (s[j]=='B') y|=2; else
			if (s[j]=='C') y|=4;
		for (int j=7; j>=0; j--) 
			if (f[j]+x<f[j|y]) f[j|y]=f[j]+x;
	}
	if (f[7]==inf) printf("-1\n"); else printf("%d\n",f[7]);
	return 0;
}