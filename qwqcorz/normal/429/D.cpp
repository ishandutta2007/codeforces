#include<bits/stdc++.h>
#define ll long long
#define dis(i,j) (sqr(x[i]-x[j])+sqr(y[i]-y[j]))
using namespace std;
const ll N=1e6+1e3;
const long double inf=9223372036854775807ll/3ll;

inline ll read() {
	register ll x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) {
		if (ch == '-') {
			f ^= 1;
		}
	}
	for (; isdigit(ch); ch = getchar()) {
		x = (x << 1) + (x << 3) + (ch ^ '0');
	}
	return f ? x : -x;
}
void print(register long double x, register char ch = '\n') {
	register ll p[20],base=1e18,now=18;
	memset(p,0,sizeof(p));
	while (base)
	{
		while (x>=base) p[now]++,x-=base;
		base/=10;
		now--;
	}
	if (x>=0.5) p[0]++;
	for (register int i=1;i<=18;i++) p[i]+=p[i-1]/10,p[i-1]%=10;
	now=18;
	while (p[now]==0) now--;
	for (register int i=now;i>=0;i--) putchar(p[i]+'0');
	putchar(ch);
}
inline long double sqr(const register long double x){return x*x;}
ll n,a[N],p[N];
long double ans=inf,x[N],y[N];
inline bool cmp(const register ll l,const register ll r)
{
	return x[l]<x[r];
}
inline void dosth()
{
	register long double rd=rand()/100.0;
	for (register ll i=1;i<=n;i++)
	{
		p[i]=i;
		const register long double X=x[i]*cos(rd)-y[i]*sin(rd);
		const register long double Y=x[i]*sin(rd)+y[i]*cos(rd);
		x[i]=X;
		y[i]=Y;
	}
	sort(p+1,p+1+n,cmp);
	for (register ll i=1;i<n;i++)
	for (register ll j=i+1;j<=min(i+5,n);j++) ans=min(ans,dis(p[i],p[j]));
}

int main()
{
	srand(time(0)*233);
	n=read();
	x[0]=y[0]=0;
	for (register ll i=1;i<=n;i++) a[i]=read();
	for (register ll i=1;i<=n;i++) x[i]=i,y[i]=y[i-1]+a[i];
	dosth();
	dosth();
	dosth();
	dosth();
	dosth();
	dosth();
	print(ans);

	return 0;
}