#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int a[N],p[N],tot[N],b[N];
void work()
{
	int n=read();
	for (int i=1;i<=n;i++) tot[i]=0;
	for (int i=1;i<=n;i++) tot[a[i]=read()]++,p[i]=i;
	sort(p+1,p+1+n,[&](int x,int y){
		return tot[a[x]]!=tot[a[y]]?tot[a[x]]>tot[a[y]]:a[x]>a[y];
	});
	int mx=tot[a[p[1]]];
	for (int i=1;i<=n;i++) b[p[(i+mx-1)%n+1]]=a[p[i]];
	for (int i=1;i<=n;i++) print(b[i]," \n"[i==n]);
}

signed main()
{
	int T=read();
	while (T--) work();
	
	return 0;
}