#include<bits/stdc++.h>
using namespace std;

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
bool Q(int x1,int y1,int x2,int y2,int x,int y)
{
	printf("? %d %d %d %d %d %d\n",x,y,x1,y1,x2,y2);
	fflush(stdout);
	return read();
}
int gcd(int x,int y)
{
	return !y?x:gcd(y,x%y);
}
inline int get(int n)
{
	int ret=0;
	for (int i=1;i<=n;i++) ret+=n%i==0;
	return ret;
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int n=read(),m=read();
	int ans1=n;
	for (int i=2,tmp=n;i<=tmp;i++)
	if (tmp%i==0)
	{
		bool flag=1;
		int now=i;
		tmp/=i;
		if (i==2) {
			if (!Q(1,1,n/2+1,1,n/2,m)) flag=0;
		}
		else {
			if (!Q(1,1,n/i*(i/2)+1,1,n/i*(i/2),m)||!Q(1,1,n/i*(i/2+1)+1,1,n/i*(i/2),m)) flag=0;
		}
		if (flag) ans1=gcd(ans1,n/i);
		while (tmp%i==0)
		{
			tmp/=i;
			now*=i;
			if (flag)
			{
				if (i==2) {
					if (!Q(1,1,n/now+1,1,n/now,m)) flag=0;
				}
				else {
					if (!Q(1,1,n/now*(now/2)+1,1,n/now*(now/2),m)||!Q(1,1,n/now*(now/2+1)+1,1,n/now*(now/2),m))
					flag=0;
				}
			}
			if (flag) ans1=gcd(ans1,n/now);
		}
	}
	int ans=get(n/ans1);
	int ans2=m;
	for (int i=2,tmp=m;i<=tmp;i++)
	if (tmp%i==0)
	{
		bool flag=1;
		int now=i;
		tmp/=i;
		if (i==2) {
			if (!Q(1,1,1,m/2+1,n,m/2)) flag=0;
		}
		else {
			if (!Q(1,1,1,m/i*(i/2)+1,n,m/i*(i/2))||!Q(1,1,1,m/i*(i/2+1)+1,n,m/i*(i/2))) flag=0;
		}
		if (flag) ans2=gcd(ans2,m/i);
		while (tmp%i==0)
		{
			tmp/=i;
			now*=i;
			if (flag)
			{
				if (i==2) {
					if (!Q(1,1,1,m/now+1,n,m/now)) flag=0;
				}
				else {
					if (!Q(1,1,1,m/now*(now/2)+1,n,m/now*(now/2))||!Q(1,1,1,m/now*(now/2+1)+1,n,m/now*(now/2)))
					flag=0;
				}
			}
			if (flag) ans2=gcd(ans2,m/now);
		}
	}
	ans*=get(m/ans2);
	putchar('!');
	putchar(' ');
	print(ans);
	fflush(stdout);
	
	return 0;
}