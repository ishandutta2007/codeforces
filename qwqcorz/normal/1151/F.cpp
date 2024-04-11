#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e2+5;
const int p=1e9+7;

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
int power(int a,int b)
{
	int ret=1;
	while (b)
	{
		if (b&1) ret=ret*a%p;
		a=a*a%p;
		b/=2;
	}
	return ret;
}
inline void Mod(int &x)
{
	if (x>=p) x-=p;
}
struct Matrix
{
	int a[N][N];
	Matrix(){memset(a,0,sizeof(a));}
}t;
struct Vector
{
	int a[N];
	Vector(){memset(a,0,sizeof(a));}
}ans;
Matrix operator *(const Matrix &a,const Matrix &b)
{
	Matrix ret;
	for (register int i=0;i<=100;i++)
	for (register int k=0;k<=100;k++)
	for (register int j=0;j<=100;j++) Mod(ret.a[i][j]+=a.a[i][k]*b.a[k][j]%p);
	return ret;
}
Vector operator *(const Matrix &a,const Vector &b)
{
	Vector ret;
	for (register int i=0;i<=100;i++)
	for (register int k=0;k<=100;k++) Mod(ret.a[k]+=b.a[i]*a.a[i][k]%p);
	return ret;
}
int a[N];

signed main()
{
	int n=read(),k=read(),x=0,y=0,sx=0,inv=power(n*(n-1)/2,p-2);
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) x+=a[i]==0;
	for (int i=1;i<=n;i++) y+=a[i]==1;
	for (int i=1;i<=x;i++) sx+=a[i]==1;
	ans.a[sx]=1;
	for (int i=0;i<=x;i++)
	{
		if (i>0     ) t.a[i][i-1]=i*i*inv%p;
		if (i<x&&i<y) t.a[i][i+1]=(x-i)*(y-i)*inv%p;
		t.a[i][i]=(n*(n-1)/2-i*i-(i<x&&i<y)*(x-i)*(y-i))*inv%p;
	}
//	for (int i=0;i<=5;i++,puts(""))
//	for (int j=0;j<=5;j++) print(t.a[i][j],' ');
	while (k)
	{
		if (k&1) ans=t*ans;
		t=t*t;
		k/=2;
	}
	print(ans.a[0]);

	return 0;
}