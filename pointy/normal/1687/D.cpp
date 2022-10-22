// By: Little09
// Problem: CF1687D Cute number
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1687D
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=6e6+5;
int n,m; 
ll a[N+5],cnt[N+5],pre[N+5],nxt[N+5];

inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
    while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
    while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
    return F*ANS;
}
int askpre(int x)
{
	if (x<0) return -1;
	if (x>N) return a[n];
	return pre[x];
}
int asknxt(int x)
{
	if (x<0) return a[1];
	if (x>N) return N+1;
	return nxt[x];
}

int main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=2;i<=n;i++) cnt[a[i]]++;
	pre[0]=-1,nxt[N+1]=N+1;
	for (int i=1;i<=N;i++)
	{
		if (cnt[i]) pre[i]=i;
		else pre[i]=pre[i-1];
	}
	for (int i=N;i>=1;i--)
	{
		if (cnt[i]) nxt[i]=i;
		else nxt[i]=nxt[i+1];
	}
	for (ll i=1;i<=a[n];i++)
	{
		if (i*(i+1)<a[1]) continue;
		ll k=i*i-a[1],resl=0,resr=i;
		if (a[1]>=i*i) resl=a[1]-i*i;
		ll l=i*i,r=i*i+i,tmp=i;
		while (1)
		{
			ll lx=l-k,rx=r-k;
			//cout << l << " " << r << endl;
			if (askpre(rx)>=lx) resr=min(resr,rx-askpre(rx));
			l=r+1,tmp++,r=tmp*tmp-1;
			//cout << l << " " << r << endl;
			lx=l-k,rx=r-k;
			l=tmp*tmp,r=tmp*tmp+tmp;
			if (asknxt(lx)<=rx) resl=max(resl,rx-asknxt(lx)+1);		
			if (l-k>a[n]) break;	
		}
		//if (i==1) cout << resl << " " << resr << endl;
		if (resl<=resr)
		{
			printf("%lld\n",k+resl);
			return 0;
		}
	}
	return 0;
}