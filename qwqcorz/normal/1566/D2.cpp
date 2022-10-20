#include<bits/stdc++.h>
using namespace std;
const int N=305*305;

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
int a[N],p[N],b[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int T=read();
	while (T--)
	{
		int n=read(),m=read(),ans=0;
		for (int i=1;i<=n*m;i++) a[i]=read();
		for (int i=1;i<=n*m;i++) p[i]=i;
		sort(p+1,p+1+n*m,[&](int x,int y){return a[x]!=a[y]?a[x]<a[y]:x>y;});
		for (int i=1,j=1;i<=n*m;i++)
		if (i==n*m||a[p[i]]!=a[p[i+1]])
		{
			int l=1,r=1;
			while (j+l-1<=i&&(j+l-1)%m) l++;
			while (i-r+1>=j&&(i-r)%m) r++;
//			print(j,' '),print(i);
//			print(l,','),print(r);
			if (j+l-1<i&&i-r+1>j)
			{
				for (int k=0,x=j,y=i-l+1;k<l;k++,x++,y++) b[x]=p[y];
				for (int k=0,x=i-r+1,y=j;k<r;k++,x++,y++) b[x]=p[y];
				for (int k=0,x=j+l,y=j+r;k<i-j+1-l-r;k++,x++,y++) b[x]=p[y];
				for (int k=j;k<=i;k++) p[k]=b[k];
			}
			j=i+1;
		}
		for (int k=0;k<n;k++)
		for (int i=1;i<=m;i++)
		for (int j=i+1;j<=m;j++) ans+=p[k*m+i]<p[k*m+j];
//		for (int i=1;i<=n*m;i++) print(p[i],",\n"[i==n*m]);
		print(ans);
	}
	
	return 0;
}
/*
1
4 2
50 50 50 50 3 50 50 50
*/