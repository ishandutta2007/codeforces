// cwt random_shuffle OI  
#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
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
char s[N];
int lcp[N][N],f[N][N],g[N][N];
bool check(int x,int y,int len)
{
	int l=lcp[x][y];
	if (l>=len) return 1;
	return s[x+l]<s[y+l];
}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
// 	freopen("a.in","r",stdin);
// 	freopen("a.out","w",stdout);
	
	scanf("%s",s+1);
	int n=strlen(s+1);
	for (int i=n;i>=1;i--)
	for (int j=n;j>=1;j--)
	lcp[i][j]=s[i]==s[j]?lcp[i+1][j+1]+1:0;
	memset(g,0x3f,sizeof(g));
	int inf=g[0][0];
	f[0][0]=1;
	g[0][0]=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<i;j++)
		if (s[j+1]!='0')
		{
			int k;
			if (j<i-j) k=0;
				  else k=check(j-(i-j)+1,j+1,i-j)?j-(i-j)+1:j-(i-j)+2;
			f[i][j+1]=f[j][k];
			g[i][j+1]=g[j][k]+1;
		}
		for (int j=i;j>=0;j--)
			f[i][j]=(f[i][j]+f[i][j+1])%p,
			g[i][j]=min(g[i][j],g[i][j+1]);
	}
	print(f[n][0]);
	int ans=p,tot=0,mul=1;
	for (int i=1;i<=min(20,n);i++,mul=mul*2%p)
		tot=(tot+(s[n-i+1]-'0')*mul)%p,
		ans=min(ans,g[n][n-i+1]+tot);
	if (ans<p) return print(ans),0;
	for (int i=21;i<=n;i++,mul=mul*2%p)
	{
		tot=(tot+(s[n-i+1]-'0')*mul)%p;
		if (g[n][n-i+1]<inf) return print((g[n][n-i+1]+tot)%p),0;
	}
	assert(false);
	
	return 0;
}