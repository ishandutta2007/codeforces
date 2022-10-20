#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

char a[N],q[N];
bitset<N>b[26];

signed main()
{
	scanf("%s",a+1);
	int n=strlen(a+1);
	for (int i=1;i<=n;i++) b[a[i]-'a'].set(i);
	int Q=read();
	while (Q--)
	if (read()==1)
	{
		int x=read();
		b[a[x]-'a'].set(x,0);
		cin>>a[x];
		b[a[x]-'a'].set(x);
	}
	else
	{
		int l=read(),r=read();
		scanf("%s",q+1);
		int m=strlen(q+1);
		bitset<N>ans; ans.flip();
		for (int i=1;i<=m;i++) ans&=b[q[i]-'a']>>i-1;
		ans>>=l;
		ans<<=l+N-1-(r-m+1);
		print(ans.count());
	}
	
	return 0;
}