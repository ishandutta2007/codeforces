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
inline int c(int x){return (x+1)/2;}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int T=read();
	while (T--)
	{
		int n=read(),s=read()-1,k=read();
		if (k>n){puts("NO");continue;}
		if (n==k){puts("YES");continue;}
		int ans=0;
		if (n%k==0) ans=c(max(n/k-3,0LL))+(k-1)*c(n/k);
		else ans=2*c(n/k-1)+(n%k-1)*c(n/k+1)+(k-1-n%k)*c(n/k);
		puts(ans>=s?"NO":"YES");
	}
	
	return 0;
}