#include<bits/stdc++.h>
#define int long long
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
inline int Log(int n)
{
	int ret=0;
	while (n) ret++,n>>=1;
	return ret;
}
int calc(int n,int m)
{
	if (m>n) return 0;
	int ret=0,now=1,tot=0,Logm=Log(m),Logn=Log(n),flag=m%2?1:2,add=0;
	while (Logm<Logn) ret+=now,now*=2,tot++,Logm++,m<<=1;
	if ((n>>tot)>(m>>tot)) add+=now;
	if ((n>>tot)==(m>>tot)) add+=(n&((1LL<<tot)-1))+1;
	if ((m&(1LL<<tot))==0)
	{
		m|=1LL<<tot;
		if ((n>>tot)>(m>>tot)) add+=now;
		if ((n>>tot)==(m>>tot)) add+=(n&((1LL<<tot)-1))+1;
	}
	return ret*flag+add;
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read(),k=read(),ans=0;
	for (int i=60;i>=0;i--) if (calc(n,ans|(1LL<<i))>=k) ans|=1LL<<i;
	print(ans);
	
	return 0;
}