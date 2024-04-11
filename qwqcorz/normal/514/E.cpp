#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e2+5;
const ll p=1e9+7;

inline int read()
{
	register int s=0;
	register char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(register int x)
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
inline void print(const register int x,const register char c='\n')
{
	write(x);
	putchar(c);
}
struct node
{
	ll m[N][N];
}a;
struct node2
{
	ll m[N];
}ans;
node operator *(node a,node b)
{
	node ans;
	for (int i=0;i<=100;i++)
	for (int j=0;j<=100;j++) ans.m[i][j]=0;
	for (int i=0;i<=100;i++)
	for (int j=0;j<=100;j++)
	for (int k=0;k<=100;k++) ans.m[i][j]=(ans.m[i][j]+a.m[i][k]*b.m[k][j]%p)%p;
	return ans;
}
node2 operator *(node2 a,node b)
{
	node2 ans;
	for (int i=0;i<=100;i++) ans.m[i]=0;
	for (int i=0;i<=100;i++)
	for (int k=0;k<=100;k++) ans.m[i]=(ans.m[i]+b.m[i][k]*a.m[k]%p)%p;
	return ans;
}
int t[101];

int main()
{
	memset(t,0,sizeof(t));
	memset(a.m,0,sizeof(a.m));
	memset(ans.m,0,sizeof(ans.m));
	int n=read(),k=read();
	for (int i=1;i<=n;i++)
	{
		int x=read();
		t[x]++;
	}
	a.m[0][0]=1;
	for (int i=1;i<=100;i++) a.m[0][i]=a.m[1][i]=t[i];
	for (int i=2;i<=100;i++) a.m[i][i-1]=1;
	ans.m[0]=1;
	ans.m[1]=1;
	while (k)
	{
		if (k&1) ans=ans*a;
		a=a*a;
		k/=2;
	}
	print(ans.m[0]);

    return 0;
}