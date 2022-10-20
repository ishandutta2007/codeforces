#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int p=998244353;
const int inv2=(p+1)/2;

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
void add(int &x,int y){x+=y;if (x>=p) x-=p;}
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
int fact[N],inv[N];
void ysgs(int n)
{
	for (int i=fact[0]=1;i<=n;i++) fact[i]=1LL*fact[i-1]*i%p;
	inv[n]=power(fact[n],p-2);
	for (int i=n;i>=1;i--) inv[i-1]=1LL*inv[i]*i%p;
}
int C(int n,int m)
{
	if (n<0||m<0||n<m) return 0;
	return 1LL*fact[n]*inv[m]%p*inv[n-m]%p;
}
char a[N];
int c=0,c0=0,c1=0;
void ins(int i,int x)
{
	if (a[i]=='b') i%2?c-=x:c+=x;
	else if (a[i]=='?') (i%2?c1:c0)+=x;
}
struct CACA
{
	int n,m,ans;
	CACA(){n=m=0,ans=1;}
	void update(int _n,int _m)
	{
		_m=min(_n,_m);
		if (_n<0||_m<0) return n=_n,m=_m,ans=0,void();
		n=max(n,-1);
		m=max(m,-1);
		while (m<_m) add(ans,C(n,++m));
		while (m>_m) add(ans,p-C(n,m--));
		while (n<_n) ans=(ans*2LL-C(n++,m)+p)%p;
		while (n>_n) ans=1LL*(ans+C(--n,m))*inv2%p;
	}
	operator long long(){return ans;}
}C1,C2,C3,C4;
int solve(int c,int c0,int c1)
{
	int cnt=c0+c1,t=c1-c;
	if (cnt==0) return (c%2==0)*abs(c1-c0)/2;
	if (cnt==1) return abs(t-abs(t)%2)/2;
	C1.update(cnt-1,t);
	C2.update(cnt-2,t-1);
	C3.update(cnt-2,cnt-1);
	C4.update(cnt-1,cnt);
	int ans=((2LL*t*C1-2LL*cnt*C2+1LL*cnt*C3-1LL*t*C4)%p+p)%p;
	return 1LL*ans*power(inv2,cnt)%p;
}

signed main(signed bangumi,char *ss1672[])
{
	(void)bangumi,(void)ss1672;
	int n=read(),m=read();
	scanf("%s",a+1);
	ysgs(n);
	for (int i=1;i<=n;i++) ins(i,1);
	print(solve(c,c0,c1));
	for (int i=1;i<=m;i++)
	{
		int x=read();
		ins(x,-1);
		cin>>a[x];
		ins(x,1);
		print(solve(c,c0,c1));
	}
	
	return 0;
}