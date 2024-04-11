#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int a[N];

void GreenDay()
{
	pair<int,int>ans(N,N);
	int n=read();
	for (int i=1;i<=n;i++) a[read()]=i;
	for (int i=0;i<N;i++) if (a[i]) ans=min(ans,make_pair(a[i],i));
	print(ans.second);
}

signed main()
{
	int T=1;
//	int T=read();
	while (T--) GreenDay();
	
	return 0;
}