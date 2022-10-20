#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int N=1e6+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int a[N];

signed main()
{
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int l=1,r=2,k=1;;l+=k+k+1,r+=k+k+2,k++)
	{
		if (r<a[1]) continue;
		int L=l<=a[1]&&a[1]<=r?a[1]-l:0;
		for (int ql=r+1,qr=l+k+k,qk=k+1;;ql+=qk+qk,qr+=qk+qk+1,qk++)
		{
			int pos=lower_bound(a+2,a+1+n,a[1]+ql-l)-a;
			if (pos>n) break;
			if (a[pos]-a[1]+l<=qr) L=max(L,qr-(a[pos]-a[1]+l)+1);
			if (L>=r-l+1) break;
		}
		if (L>=r-l+1) continue;
		int R=0;
		for (int ql=r+1,qr=l+k+k,qk=k+1;;ql+=qk+qk,qr+=qk+qk+1,qk++)
		{
			int pos=upper_bound(a+2,a+1+n,a[1]+qr-r)-a-1;
			if (a[pos]-a[1]+r>=ql) R=max(R,(a[pos]-a[1]+r)-ql+1);
			if (a[1]+ql-r>a[n]) break;
			if (L+R>=r-l+1) break;
		}
		if (L+R<r-l+1) return print(l+L-a[1]),0;
	}
	
	return 0;
}