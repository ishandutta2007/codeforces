#include<bits/stdc++.h>
using namespace std;

char s[100010],opt[3],sa[301],sb[301],sc[301];
int f[251][251][251],n,q,na,nb,nc,nw,nxt[100010][27];

void check(int i,int j,int k)
{
	f[i][j][k]=n+1;
	if (i>0) f[i][j][k]=min(f[i][j][k],nxt[f[i-1][j][k]+1][sa[i]-'a']);
	if (j>0) f[i][j][k]=min(f[i][j][k],nxt[f[i][j-1][k]+1][sb[j]-'a']);
	if (k>0) f[i][j][k]=min(f[i][j][k],nxt[f[i][j][k-1]+1][sc[k]-'a']);
}

int main()
{
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	for (int i=0; i<26; i++) nxt[n+1][i]=nxt[n+2][i]=n+1;
	for (int i=n; i; i--)
	{
		memcpy(nxt[i],nxt[i+1],sizeof(nxt[i]));
		nxt[i][s[i]-'a']=i;
	}
	for (int i=0; i<=250; i++)
		for (int j=0; j<=250; j++)
			for (int k=0; k<=250; k++) f[i][j][k]=n+1;
	f[0][0][0]=na=nb=nc=0;
	while (q--)
	{
		scanf("%s",opt);
		if (opt[0]=='+')
		{
			scanf("%d%s",&nw,opt);
			if (nw==1)
			{
				sa[++na]=opt[0];
				for (int i=0; i<=nb; i++)
					for (int j=0; j<=nc; j++)
						check(na,i,j);
			} else
			if (nw==2)
			{
				sb[++nb]=opt[0];
				for (int i=0; i<=na; i++)
					for (int j=0; j<=nc; j++)
						check(i,nb,j);
			} else
			{
				sc[++nc]=opt[0];
				for (int i=0; i<=na; i++)
					for (int j=0; j<=nb; j++)
						check(i,j,nc);
			}
		} else
		{
			scanf("%d",&nw);
			if (nw==1) na--; else
			if (nw==2) nb--; else nc--;
		}
		puts(f[na][nb][nc]<=n?"YES":"NO");
	}
	return 0;
}