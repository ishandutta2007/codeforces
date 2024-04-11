#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=105;
const int M=1e3+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int a[N];
bitset<N*M>f;
signed main()
{
	int n=read(),sum=0;
	for (int i=1;i<=n;i++) sum+=a[i]=read();
	if (sum&1) return puts("0"),0;
	sum/=2;
	f.set(0);
	for (int i=1;i<=n;i++) f|=f<<a[i];
	if (!f[sum]) return puts("0"),0;
	pair<int,int>ans(N,N);
	for (int i=1;i<=n;i++)
	{
		int x=a[i],tot=0;
		while (x%2==0) x/=2,tot++;
		ans=min(ans,make_pair(tot,i));
	}
	puts("1");
	print(ans.second);
	
	return 0;
}