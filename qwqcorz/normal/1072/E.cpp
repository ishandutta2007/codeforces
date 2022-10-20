#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;

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
bool flag=0;
int u[N],v[N],w[N],cnt=0;
int a[N];
bool checkl(int l,int x,int y,int z)
{
	return a[l]==x&&a[l+1]==y&&a[l+2]==z;
}
bool checkr(int r,int x,int y,int z)
{
	return a[r]==x&&a[r-1]==y&&a[r-2]==z;
}
void reverse(int x,int y,int z)
{
	++cnt;
	u[cnt]=x;
	v[cnt]=y;
	w[cnt]=z;
	a[x]^=1;
	a[y]^=1;
	a[z]^=1;
}
void reverse(int x,int y)
{
	reverse(x,(x+y)/2,y);
}
int n,opL[N],opR[N],opcnt=0,tmp[N];
bool judge(int l,int r)
{
	for (int i=l;i<=r;i++)
	if (tmp[i]) return 0;
	return 1;
}
void bf(int l,int r)
{
	for (int i=l;i<=r;i++)
	for (int j=i+2;j<=r;j+=2)
	{
		++opcnt;
		opL[opcnt]=i;
		opR[opcnt]=j;
//		print(i,' ');
//		print(j);
	}
	for (int st=0;st<(1<<opcnt);st++)
	{
		for (int i=l;i<=r;i++) tmp[i]=a[i];
		for (int i=1;i<=opcnt;i++)
		if (st&(1<<(i-1)))
		{
			tmp[opL[i]]^=1;
			tmp[opR[i]]^=1;
			tmp[(opL[i]+opR[i])/2]^=1;
		}
		if (judge(l,r))
		{
			flag=1;
			for (int i=1;i<=opcnt;i++)
			if (st&(1<<(i-1)))
			reverse(opL[i],opR[i]);
			return;
		}
	}
}
void solve(int l,int r)
{
	if (r-l+1<=8)
	{
		while (1<l&&r-l+1<8) l--;
		while (r<n&&r-l+1<8) r++;
		return bf(l,r);
	}
	if (!a[l]) return solve(l+1,r);
	if (!a[r]) return solve(l,r-1);
	if (checkl(l,1,1,1)) return reverse(l,l+1,l+2),solve(l+3,r);
	if (checkl(l,1,0,1)) return reverse(l,l+2,l+4),solve(l+3,r);
	if (checkl(l,1,0,0)) return reverse(l,l+3,l+6),solve(l+3,r);
	if (checkr(r,1,1,1)) return reverse(r-2,r-1,r),solve(l,r-3);
	if (checkr(r,1,0,1)) return reverse(r-4,r-2,r),solve(l,r-3);
	if (checkr(r,1,0,0)) return reverse(r-6,r-3,r),solve(l,r-3);
	if ((r-l)&1)
	{
		reverse(l,r-1);
		reverse(l+1,r);
		return solve(l+2,r-2);
	}
	else
	{
		reverse(l,r);
		reverse(l+1,r-1);
		return solve(l+2,r-2);
	}
}

signed main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	solve(1,n);
	if (flag)
	{
		puts("YES");
		print(cnt);
		for (int i=1;i<=cnt;i++)
		{
			print(u[i],' ');
			print(v[i],' ');
			print(w[i]);
		}
	}
	else puts("NO");

	return 0;
}