#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;
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
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
inline void add(int &x,int y)
{
	x+=y;
	if (x>=p) x-=p;
}
int f[N][N*N],C[N][N],a[N];

signed main()
{
	int n=read(),ans=0;
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	memset(f,0,sizeof(f));
	f[0][0]=1;
	for (int i=1,sum=a[1];i<=n;sum+=a[++i])
	for (int j=i;j>=1;j--)
	for (int k=a[i];k<=sum;k++)
	add(f[j][k],f[j-1][k-a[i]]);
//	for (int j=1;j<=n;j++,puts(""))
//	for (int k=0;k<=9;k++) print(f[j][k],' ');
	memset(C,0,sizeof(C));
	C[0][0]=1;
	for (int i=1;i<=n;i++)
	for (int j=C[i][0]=1;j<=i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%p;
	int tota=0,totb=0,cnt=0;
	for (int i=1;i<=n;i++)
	{
		if (i==1||a[i]!=a[i-1])
		{
			cnt++;
			tota=1;
			totb=1;
			int now=i;
			while (now<n&&a[now]==a[now+1])
			{
				now++;
				tota++;
			}
		}
		else totb++;
//		print(tota,' ');
//		print(totb,':');
//		print(f[totb][a[i]*totb]);
		if (f[totb][a[i]*totb]==C[tota][totb]) ans=max(ans,totb);
	}
	print(cnt==2?n:ans);

	return 0;
}