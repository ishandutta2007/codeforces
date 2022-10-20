#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int N=35;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}
int a[N];
signed main()
{
	int asdf=0;
	int n=read(),Q=read();
	for (int i=0;i<n;i++) a[i]=read();
	for (int T=1;T<=Q;T++)
	{
		int opt=read(),x=read(),k=read();
		if (opt==1) a[x]=k;
		else
		{
			int all=0;
			for (int i=0;i<n;i++) all+=(1LL<<i)*a[i];
			if (all<k){puts("-1");continue;}
			for (int i=0;i<=x;i++) k-=a[i];
			if (k<=0){puts("0");continue;}
			int pos=-1,sum=0,ans=0;
			for (int i=1;i<=x;i++) sum+=((1LL<<i)-1)*a[i];
			for (int i=x+1;i<n;i++)
			{
				int t=min(k/(1LL<<i-x),a[i]);
				k-=(1LL<<i-x)*t,sum+=((1LL<<i)-(1LL<<i-x))*t,ans+=((1LL<<i-x)-1)*t;
				if (t<a[i]){pos=i;break;}
			}
			if (pos<0){print(ans+k);continue;}
			if (sum<k)
			for (int i=pos;i>x;i--)
			{
				ans++;
				if (i==x+1){k-=2;break;}
				if ((1LL<<i-1-x)<=k) k-=1LL<<i-1-x,sum+=(1LL<<i-1)-(1LL<<i-1-x),ans+=(1LL<<i-1-x)-1;
				if (sum>=k) break;
			}
			print(ans+max(k,0LL));
		}
	}
	
	return 0;
}
/*
10 1
88319 65830 687092 330564 436262 281795 746582 181351 578010 670433
2 0 527228638

10 1
1 2 2 1 0 0 0 1 1 1
2 2 21

*/