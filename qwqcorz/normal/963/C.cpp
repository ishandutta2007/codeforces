#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;

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
int gcd(int x,int y){return !y?x:gcd(y,x%y);}
int a[N],b[N],c[N];
map<int,int>t1,t2;

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int n=read(),sum=0,g=0,ans=0;
	for (int i=1;i<=n;i++)
	{
		a[i]=read(),b[i]=read(),c[i]=read();
		t1[a[i]]+=c[i],t2[b[i]]+=c[i];
		sum+=c[i],g=gcd(g,c[i]);
	}
	for (int i=1;i<=n;i++) if (1.0*t1[a[i]]/c[i]!=1.0*sum/t2[b[i]]) return puts("0"),0;
	for (int i=1;i*i<=g;i++) if (g%i==0) ans+=1+(i*i<g);
	print(ans);
	
	return 0;
}