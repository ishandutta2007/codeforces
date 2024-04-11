#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
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
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
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
		if (b&1) ret=1LL*ret*a%p;
		a=1LL*a*a%p;
		b/=2;
	}
	return ret;
}
struct node
{
	int a[4];
	int value()
	{
		int ret=1;
		for (int i=0;i<4;i++) ret=1LL*ret*power(i,a[i])%p;
		return ret;
	}
	node &operator +=(const int &x)
	{
		a[x]++;
		return *this;
	}
	node &operator -=(const int &x)
	{
		a[x]--;
		return *this;
	}
}x[N][N],y[N][N],u[N*2][N],v[N*2][N],ans=(node){1,0,0,0},tmp;
bool operator <(node a,node b)
{
//	return a.value()<b.value();
	if (b.a[0]) return 0;
	if (a.a[0]) return 1;
	int mn=min(a.a[2],b.a[2]);
	a.a[2]-=mn,b.a[2]-=mn;
	mn=min(a.a[3],b.a[3]);
	a.a[3]-=mn,b.a[3]-=mn;
	int x1,y1,x2,y2;
	if (a.a[2]) x1=2,y1=a.a[2];
		   else x1=3,y1=a.a[3];
	if (b.a[2]) x2=2,y2=b.a[2];
		   else x2=3,y2=b.a[3];
	return log(x1)*y1<log(x2)*y2;
}
node operator *(const node &a,const node &b)
{
	node ret;
	for (int i=0;i<4;i++) ret.a[i]=a.a[i]+b.a[i];
	return ret;
}
node operator /(const node &a,const node &b)
{
	node ret;
	for (int i=0;i<4;i++) ret.a[i]=a.a[i]-b.a[i];
	return ret;
}
char a[N][N];
node calcx(int i,int l,int r){return x[i][r]/x[i][l-1];}
node calcy(int i,int l,int r){return y[i][r]/y[i][l-1];}
node calcu(int i,int l,int r){return u[i][r]/u[i][l-1];}
node calcv(int i,int l,int r){return v[i][r]/v[i][l-1];}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read();
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	{
		a[i][j]=getchar();
		while (a[i][j]<'0'||'3'<a[i][j]) a[i][j]=getchar();
		a[i][j]-='0';
		x[i][j]+=a[i][j];
		y[j][i]+=a[i][j];
		u[i+j][i]+=a[i][j];
		v[i-j+N][i]+=a[i][j];
	}
	for (int i=0;i<N;i++)
	for (int j=1;j<=n;j++)
		x[i][j]=x[i][j]*x[i][j-1],
		y[i][j]=y[i][j]*y[i][j-1];
	for (int i=0;i<N*2;i++)
	for (int j=1;j<=n;j++)
		u[i][j]=u[i][j]*u[i][j-1],
		v[i][j]=v[i][j]*v[i][j-1];
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	if (a[i][j])
	{
		int l=0,r=min(min(n-j,j-1),min(n-i,i-1));
		while (l<=r)
		{
			int mid=(l+r)/2;
			if ((calcx(i,j-mid,j+mid)*calcy(j,i-mid,i+mid)).a[0]) r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,(tmp=calcx(i,j-r,j+r)*calcy(j,i-r,i+r))-=a[i][j]);
		l=0,r=min(min(n-j,j-1),min(n-i,i-1));
		while (l<=r)
		{
			int mid=(l+r)/2;
			if ((calcu(i+j,i-mid,i+mid)*calcv(i-j+N,i-mid,i+mid)).a[0]) r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,(tmp=calcu(i+j,i-r,i+r)*calcv(i-j+N,i-r,i+r))-=a[i][j]);
	}
	print(ans.value());
	
	return 0;
}