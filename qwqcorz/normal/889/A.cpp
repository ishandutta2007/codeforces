#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int tot[N];
void GreenDay()
{
	int n=read(),ans=0;
	for (int i=1;i<=n;i++)
	{
		int x=read();
		if (tot[x]) tot[x]--,tot[i]++;
			   else tot[i]++,ans++;
	}
	print(ans);
}

signed main()
{
	int T=1;
//	int T=read();
	while (T--) GreenDay();
	
	return 0;
}