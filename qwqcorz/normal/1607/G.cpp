#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int a[N],b[N],n,m,l,r,L[N],R[N];
void solve(int ans)
{
	print(abs(ans));
	int sum=ans-l;
	for (int i=1;i<=n;i++)
	{
		int d=min(sum/2,R[i]-L[i]);
		sum-=d*2;
		int k=R[i]-d;
		print(k,' '),print(m-k);
	}
}
void GreenDay()
{
	n=read(),m=read(),l=0,r=0;
	for (int i=1;i<=n;i++)
	{
		a[i]=read(),b[i]=read();
		int L=max(m-b[i],0LL),R=min(a[i],m);
		l+=(a[i]-R)-(b[i]-(m-R));
		r+=(a[i]-L)-(b[i]-(m-L));
		::L[i]=L,::R[i]=R;
	}
	if (l>0) return solve(l);
	if (r<0) return solve(r);
	solve(r%2);
}

signed main()
{
//	int T=1;
	int T=read();
	while (T--) GreenDay();
	
	return 0;
}