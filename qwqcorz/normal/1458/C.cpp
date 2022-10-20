#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
const int M=1e5+5;

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
struct node
{
	int id,add;
}p[3];
int a[N][N],ans[N][N];
char c[M];

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int T=read();
	while (T--)
	{
		p[0]=(node){0,0};
		p[1]=(node){1,0};
		p[2]=(node){2,0};
		int n=read(),q=read();
		for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) a[i][j]=read();
		scanf("%s",c+1);
		for (int i=1;i<=q;i++)
		{
			char opt=c[i];
			if (opt=='U') p[0].add--;
			if (opt=='D') p[0].add++;
			if (opt=='L') p[1].add--;
			if (opt=='R') p[1].add++;
			if (opt=='I') swap(p[1],p[2]);
			if (opt=='C') swap(p[0],p[2]);
		}
//		for (int i=0;i<3;i++) print(p[i].id,' '),print(p[i].add);
		for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			int x[3]={i,j,a[i][j]},nxt[3];
			for (int k=0;k<3;k++) nxt[k]=((x[p[k].id]+p[k].add)%n+n-1)%n+1;
			ans[nxt[0]][nxt[1]]=nxt[2];
		}
		for (int i=1;i<=n;i++,puts(""))
		for (int j=1;j<=n;j++) print(ans[i][j],' ');
	}
	
	return 0;
}