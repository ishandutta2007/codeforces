// cwt random_shuffle OI  
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
const int p=1919810111;
const int mod=1e9+7;

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
		if (b&1) ret=ret*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return ret;
}
int ax,ay;
int exgcd(int x,int y)
{
	if (!y) return ax=1,ay=0,x;
	int g=exgcd(y,x%y),tx=ax,ty=ay;
	ax=ty;
	ay=tx-(x/y)*ty;
	return g;
}
unordered_map<int,int>mp;
int a[N],b[N];
inline int fix(int x,int y){return (x%y+y)%y;}
void merge(int &x,int &y,int a,int b)
{
//	print(x,','),print(y,' ');
//	print(a,','),print(b,':');puts("");
	if (y==0||b==0)
	{
		if (y==0&&b==0)
		{
			if (x==a) return;
			puts("-1"),exit(0);
		}
		if (y==0) swap(x,a),swap(y,b);
		if (a>=x&&(a-x)%y==0) x=a,y=b;
						 else puts("-1"),exit(0);
		return;
	}
	if (y==b)
	{
		if (x<a) swap(x,a);
		if ((x-a)%b) puts("-1"),exit(0);
		return;
	}
	int g=exgcd(y,-b);
	if ((a-x)%g) puts("-1"),exit(0);
	x=fix(ax,b)*fix(((a-x)/g),b)%b*y+x;
	y=b/abs(g)*y;
//	print(x,','),print(y);
}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
// 	freopen("d.in","r",stdin);
// 	freopen("d.out","w",stdout);
	
	int n=read(),x=0,y=1;
	for (int i=1;i<=n;i++) a[i]=read(),b[i]=read();
	int A=a[1]%mod,B=b[1]%mod;
	for (int i=0,mul1=a[1]%p,mul2=a[1]%mod;i<=120;i++,mul1=mul1*(b[1]%p)%p,mul2=mul2*(b[1]%mod)%mod)
	mp[mul2*p+mul1]=i;
	for (int i=2;i<=n;i++)
	{
		vector<int>pos;
		for (int j=0,mul1=a[i]%p,mul2=a[i]%mod;j<=120;j++,mul1=mul1*(b[i]%p)%p,mul2=mul2*(b[i]%mod)%mod)
		if (mp.count(mul2*p+mul1))
		{
			pos.push_back(mp[mul2*p+mul1]);
			if ((int)pos.size()==2) break;
		}
		if (pos.empty()) return puts("-1"),0;
		if ((int)pos.size()==1) pos.push_back(pos[0]);
		merge(x,y,pos[0],pos[1]-pos[0]);
	}
	print(A*power(B,x)%mod);
	
//	int tx=2,ty=3;
//	merge(tx,ty,3,2);
	
	return 0;
}
/*
4
1 2
32768 65536
4 8
256 512
*/

/*// cwt random_shuffle OI  
#include<bits/stdc++.h>
#define int long long
#define ll __int128
using namespace std;
const int N=1e6+5;
const int p1=(int)1e18+3;
const int p2=(int)1e18-11;
const int mod=1e9+7;

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
		if (b&1) ret=ret*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return ret;
}
int ax,ay;
int exgcd(int x,int y)
{
	if (!y) return ax=1,ay=0,x;
	int g=exgcd(y,x%y),tx=ax,ty=ay;
	ax=ty;
	ay=tx-(x/y)*ty;
	return g;
}
unordered_map<ll,int>mp;
int a[N],b[N];
inline int fix(int x,int y){return (x%y+y)%y;}
void merge(int &x,int &y,int a,int b)
{
//	print(x,','),print(y,' ');
//	print(a,','),print(b,':');puts("");
	if (y==0||b==0)
	{
		if (y==0&&b==0)
		{
			if (x==a) return;
			puts("-1"),exit(0);
		}
		if (y==0) swap(x,a),swap(y,b);
		if (a>=x&&(a-x)%y==0) x=a,y=b;
						 else puts("-1"),exit(0);
		return;
	}
	if (y==b)
	{
		if (x<a) swap(x,a);
		if ((x-a)%b) puts("-1"),exit(0);
		return;
	}
	int g=exgcd(y,-b);
	if ((a-x)%g) puts("-1"),exit(0);
	x=fix(ax,b)*fix(((a-x)/g),b)%b*y+x;
	y=b/abs(g)*y;
//	print(x,','),print(y);
}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	
	int n=read(),x=0,y=1;
	for (int i=1;i<=n;i++) a[i]=read(),b[i]=read();
	int A=a[1]%mod,B=b[1]%mod;
	ll mul1=a[1]%p1,mul2=a[1]%p2;
	for (int i=0;i<=120;i++,mul1=mul1*b[1]%p1,mul2=mul2*b[1]%p2)
	mp[mul2*p1+mul1]=i;
	for (int i=2;i<=n;i++)
	{
		vector<int>pos;
		ll mul1=a[i]%p1,mul2=a[i]%p2;
		for (int j=0;j<=120;j++,mul1=mul1*b[i]%p1,mul2=mul2*b[i]%p2)
		if (mp.count(mul2*p1+mul1))
		{
			pos.push_back(mp[mul2*p1+mul1]);
			if ((int)pos.size()==2) break;
		}
		if (pos.empty()) return puts("-1"),0;
		if ((int)pos.size()==1) pos.push_back(pos[0]);
		merge(x,y,pos[0],pos[1]-pos[0]);
	}
	print(A*power(B,x)%mod);
	
//	int tx=2,ty=3;
//	merge(tx,ty,3,2);
	
	return 0;
}
/*
4
1 2
32768 65536
4 8
256 512
*/