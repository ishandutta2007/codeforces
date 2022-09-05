#include<bits/stdc++.h>
using namespace std;

bool f[2010][2010];
int n,x,a[10],k,la[2010][2010],g[2010][2010],bc[131],b[2010];
char s[10];

int calc(int x)
{
	int ans=0;
	for (int i=1; i<=7; i++) ans=(ans<<1|(x%10)),x/=10;
	return ans;
}

int main()
{
	bc[0]=0;
	for (int i=1; i<128; i++) bc[i]=bc[i^(i&-i)]+1;
	scanf("%d%d",&n,&k);
	a[0]=calc(1110111);
	a[1]=calc(10010);
	a[2]=calc(1011101);
	a[3]=calc(1011011);
	a[4]=calc(111010);
	a[5]=calc(1101011);
	a[6]=calc(1101111);
	a[7]=calc(1010010);
	a[8]=calc(1111111);
	a[9]=calc(1111011);
	for (int i=1; i<=n; i++)
	{
		scanf("%s",s),x=0;
		for (int j=0; j<7; j++) x=x*10+(s[j]-'0');
		b[i]=calc(x);
	}
	f[n+1][0]=1;
	for (int i=n; i; i--)
		for (int j=9; j>=0; j--)
			if ((a[j]&b[i])==b[i])
			{
				int val=bc[a[j]^b[i]];
				for (int l=0; l+val<=k; l++)
					if (f[i+1][l]&&!f[i][l+val]) f[i][l+val]=1,la[i][l+val]=l,g[i][l+val]=j;
			}
	if (!f[1][k]) puts("-1"); else
	{
		for (int i=1,nw=k; i<=n; i++)
		{
			printf("%d",g[i][nw]);
			nw=la[i][nw];
		}
	}
	return 0;
}