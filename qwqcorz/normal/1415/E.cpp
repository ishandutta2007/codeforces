#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int a[N];

signed main()
{
	ll ans=0;
	priority_queue<ll>q;
	int n=read(),k=read()+1;
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n,greater<int>());
	for (int i=1;i<=k;i++) q.push(0);
	for (int i=1;i<=n;i++)
	{
		ll now=q.top();
		q.pop();
		ans+=now;
		now+=a[i];
		q.push(now);
	}
	print(ans);
	
	return 0;
}