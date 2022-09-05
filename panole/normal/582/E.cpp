#include<bits/stdc++.h>
using namespace std;

const int mod=1000000007;
int f[260][65537],n,m,l,r,A,B,C,D,E,cnt,ans,F[65537],G[65537],fl[65537],fr[65537],gl[65537],gr[65537],g[9][65537],ord[1010];
char s[510];

void add(int &x,int y) {x=(x+y>=mod?x+y-mod:x+y);}

void solve(int x,int l,int r)
{
	if (l==r)
	{
		for (int i=0; i<65536; i++) f[x][i]=g[ord[s[l]]][i];
		return;
	}
	int nw=0,po,ls,rs;
	for (int i=l; i<=r; i++)
	{
		if (s[i]=='(') nw++; else
		if (s[i]==')') nw--;
		if (nw==0) {po=i+1; break;}
	}
	ls=(++cnt),solve(ls,l+1,po-2);
	rs=(++cnt),solve(rs,po+2,r-1);
	for (int i=0; i<65536; i++) fl[i]=gl[i]=f[ls][i],fr[i]=gr[i]=f[rs][i];
	for (int i=1; i<65536; i<<=1)
		for (int j=0; j<65536; j+=(i<<1))
			for (int k=0; k<i; k++)
				add(fl[i+j+k],fl[j+k]),add(fr[i+j+k],fr[j+k]),
				add(gl[j+k],gl[i+j+k]),add(gr[j+k],gr[i+j+k]);
	for (int i=0; i<65536; i++) F[i]=1ll*fl[i]*fr[i]%mod,G[i]=1ll*gl[i]*gr[i]%mod;
	for (int i=1; i<65536; i<<=1)
		for (int j=0; j<65536; j+=(i<<1))
			for (int k=0; k<i; k++)
				add(F[i+j+k],mod-F[j+k]),add(G[j+k],mod-G[i+j+k]);
	if (s[po]!='&') for (int i=0; i<65536; i++) add(f[x][i],F[i]);
	if (s[po]!='|') for (int i=0; i<65536; i++) add(f[x][i],G[i]);
}

int main()
{
	ord['A']=3,ord['B']=2,ord['C']=1,ord['D']=0;
	ord['a']=7,ord['b']=6,ord['c']=5,ord['d']=4;
	ord['?']=8,memset(g,0,sizeof(g));
	for (int nw,i=0; i<8; i++)
	{
		nw=0;
		for (int j=0; j<16; j++) nw|=(((j>>(i&3)&1)^(i>=4))<<j);
		g[i][nw]=1;
	}
	for (int i=0; i<8; i++)
		for (int j=0; j<65536; j++) g[8][j]+=g[i][j];
	scanf("%s",s+1),scanf("%d",&m);
	n=strlen(s+1),l=0,r=(1<<16)-1;
	for (int i=1; i<=m; i++) 
	{
		scanf("%d%d%d%d%d",&A,&B,&C,&D,&E),A=(A<<3)|(B<<2)|(C<<1)|(D);
		if (E) l^=(1<<A); else r^=(1<<A);
	}
	cnt=1,solve(1,1,n),ans=0;
	for (int i=0; i<65536; i++)
		if ((l&i)==l&&(r&i)==i) add(ans,f[1][i]);
	printf("%d\n",ans);
	return 0;
}