#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int a[N];
bool check(int n,int k,int mid)
{
	for (int i=mid;i<=n;i++) if (a[i]>k) k--;
	return k>=0;
}
void work()
{
	int n=read(),k=read();
	for (int i=1;i<=n;i++) a[i]=read();
	int l=1,r=n;
	while (l<=r)
	{
		int mid=(l+r)/2;
		if (check(n,k,mid)) r=mid-1;
					   else l=mid+1;
	}
	for (int i=1;i<=n;i++)
	if (a[i]<=k) putchar('1');
	else if (i>=l) putchar('1'),k--;
	else putchar('0');
	putchar('\n');
}

signed main()
{
	int T=read();
	while (T--) work(); 
	
	return 0;
}