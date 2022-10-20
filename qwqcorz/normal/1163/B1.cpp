#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int t[N],cnt=0,tot[N];

void GreenDay()
{
	int n=read(),ans=0,sum=0;
	for (int i=1;i<=n;i++)
	{
		int x=read();
		if (tot[x]) if (!--t[tot[x]]) cnt--,sum^=tot[x];
		if (!t[++tot[x]]++) cnt++,sum^=tot[x];
		if (cnt==1&&(tot[x]==1||t[tot[x]]==1)) ans=i;
		if (cnt==2)
		{
			int a=tot[x],b=a^sum;
			if (t[b]==1&&(b==1||b==a+1)) ans=i;
			swap(a,b);
			if (t[b]==1&&(b==1||b==a+1)) ans=i;
		}
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