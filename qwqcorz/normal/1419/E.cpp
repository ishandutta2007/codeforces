#include<bits/stdc++.h>
using namespace std;
const int N=4e4+5;

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
map<int,bool>m;
int a[N],p[N],b[N];

signed main()
{
	int T=read();
	while (T--)
	{
		m.clear();
		int num=read(),sq=sqrt(num),n=0,cnt=0,tmp=num;
		for (int i=2;i<=sq;i++)
		if (num%i==0)
		{
			(i);
			a[++n]=i;
			if (i!=num/i) a[++n]=num/i;
		}
		a[++n]=num;
		for (int i=2;i<=sq;i++)
		if (num%i==0)
		{
			p[++cnt]=i;
			while (num%i==0) num/=i;
		}
		if (num>1) p[++cnt]=num;
		num=tmp;
		for (int i=1;i<=n;i++) m[a[i]]=1;
		p[cnt+1]=p[1];
		for (int i=1;i<=cnt;i++)
		{
			m[p[i]]=0;
			if (i<cnt||cnt>2) m[p[i]*p[i+1]]=0;
			if (i==cnt&&cnt==2&&n>3) m[num]=0;
		}
		for (int i=1;i<=cnt;i++)
		{
			print(p[i],' ');
			for (int j=1;j<=n;j++)
			if (a[j]%p[i]==0)
			if (m.count(a[j])&&m[a[j]]==1)
			{
				m[a[j]]=0;
				print(a[j],' ');
			}
			if (i<cnt||cnt>2) print(p[i]*p[i+1],' ');
			if (i==cnt&&cnt==2&&n>3) print(num,' ');
		}
		putchar('\n');
		if (cnt==2&&n<=3) print(1);
					 else print(0);
	}

	return 0;
}