#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=65;
const int K=2e3+5;
const int p=1e9+7;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
inline int Log(int x)
{
	int ret=0;
	while (x) x>>=1,ret++;
	return ret;
}
vector<int>a;
map<int,int>col,id;
int f[N*K][6],g[N][6],cnt=0;

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int m=read(),ans=0;
	for (int i=0;i<6;i++) g[1][i]=1;
	for (int i=2;i<=m;i++)
	for (int j=0;j<6;j++)
	for (int k=0;k<6;k++)
	for (int t=0;t<6;t++)
	if ((j&~1)!=(k&~1)&&(j&~1)!=(t&~1))
	g[i][j]=(g[i][j]+g[i-1][k]*g[i-1][t])%p;
	int n=read();
	for (int i=1;i<=n;i++)
	{
		int x=read(),y=0;
		char c; cin>>c;
		if (c=='w') y=0;
		if (c=='y') y=1;
		if (c=='g') y=2;
		if (c=='b') y=3;
		if (c=='r') y=4;
		if (c=='o') y=5;
		col[x]=y;
		for (;x;x/=2)
		if (!id.count(x))
		id[x]=++cnt;
	}
	auto now=id.end();
	while (now!=id.begin())
	{
		now--;
		int x=now->first,ID=now->second,l=Log(x);
		if (l==m){f[ID][col[x]]=1;continue;}
		int ls=x*2,rs=x*2+1;
		int *A,*B;
		if (id.count(ls)) A=f[id[ls]];
					 else A=g[m-l];
		if (id.count(rs)) B=f[id[rs]];
					 else B=g[m-l];
		for (int i=0;i<6;i++)
		for (int j=0;j<6;j++)
		for (int k=0;k<6;k++)
		if ((i&~1)!=(j&~1)&&(i&~1)!=(k&~1))
		f[ID][i]=(f[ID][i]+A[j]*B[k])%p;
		if (col.count(x))
		for (int i=0,c=col[x];i<6;i++)
		if (i!=c) f[ID][i]=0;
	}
	for (int i=0;i<6;i++) ans=(ans+f[id.begin()->second][i])%p;
	print(ans);
	
	return 0;
}