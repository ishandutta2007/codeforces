#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;

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
int a[N],x[N],y[N];
map<int,vector<int>>one;

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int T=read();
	while (T--)
	{
		int n=read(),q=read();
		x[0]=y[n+1]=0;
		scanf("%s",s+1);
		for (int i=1;i<=n;i++) a[i]=(s[i]=='+'?1:-1)*(i%2?1:-1);
		for (int i=1;i<=n;i++) x[i]=x[i-1]+a[i];
		for (int i=1;i<=n;i++) x[i]-=a[i];
		for (int i=n;i>=1;i--) y[i]=y[i+1]-a[i];
		for (int i=n;i>=1;i--) y[i]+=a[i];
		for (int i=1;i<=n;i++) a[i]+=a[i-1];
		one.clear();
		for (int i=1;i<=n;i++) one[x[i]+y[i]].push_back(i); 
		while (q--)
		{
			int l=read(),r=read();
			if (a[r]-a[l-1]==0) puts("0");
			else if ((r-l)%2==0)
			{
				puts("1");
				int pos=*lower_bound(one[x[l]+y[r]].begin(),one[x[l]+y[r]].end(),l);
				print(pos);
			}
			else
			{
				puts("2");
				int pos=*lower_bound(one[x[l]+y[r-1]].begin(),one[x[l]+y[r-1]].end(),l);
				print(pos,' '),print(r);
			}
		}
	}
	
	return 0;
}