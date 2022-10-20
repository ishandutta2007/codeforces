#include<bits/stdc++.h>
using namespace std;
const int N=505;

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
int c[N],p[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read(),k=read(),ans=0,sum=n;
	if (n%2==1&&k%2==0) return puts("-1"),fflush(stdout),0;
	for (int i=1;i<=n;i++) p[i]=i;
	for (int i=1;i<=n;i++) c[i]=1;
	bool flag=!(sum%k==0&&sum/k>=c[1]);
	while (flag)
	for (int i=1;i<=n;i++)
	{
		c[i]+=2,sum+=2;
		if (sum%k==0&&sum/k>=c[1])
		{
			flag=0;
			break;
		}
	}
	for (int i=1;i<=sum/k;i++)
	{
		sort(p+1,p+1+n,[&](int x,int y){return c[x]>c[y];});
		putchar('?');
		for (int j=1;j<=k;j++) c[p[j]]--,printf(" %d",p[j]);
		cout<<endl; ans^=read();
	}
	cout<<"! "; print(ans);
	
	return 0;
}