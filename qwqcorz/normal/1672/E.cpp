#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int ask(int x)
{
	cout<<"? "<<x<<endl;
	return read();
}

signed main()
{
	int n=read(),l=1,r=5e6;
	while (l<=r)
	{
		int mid=(l+r)/2;
		if (ask(mid)==1) r=mid-1;
					else l=mid+1;
	}
	int s=l+1,ans=l;
	for (int i=2;i<=n;i++)
	{
		int tmp=ask((s-1)/i);
		if (tmp) ans=min(ans,(s-1)/i*tmp);
	}
	cout<<"! "<<ans<<endl;
	
	return 0;
}