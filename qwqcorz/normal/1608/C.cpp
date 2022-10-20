#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

bool ans[N];
int a[N],b[N],p[N],q[N],np[N],nq[N],x[N],y[N],mx[N],my[N];
void GreenDay()
{
	int n=read();
	for (int i=1;i<=n;i++) ans[i]=0;
	for (int i=1;i<=n;i++) a[i]=read(),p[i]=i;
	for (int i=1;i<=n;i++) b[i]=read(),q[i]=i;
	sort(p+1,p+1+n,[&](int x,int y){return a[x]<a[y];});
	sort(q+1,q+1+n,[&](int x,int y){return b[x]<b[y];});
	for (int i=1;i<=n;i++) np[p[i]]=i,nq[q[i]]=i;
	for (int i=1;i<=n;i++) x[np[i]]=nq[i],y[nq[i]]=np[i];
	for (int i=1;i<=n;i++) mx[i]=max(mx[i-1],x[i]);
	for (int i=1;i<=n;i++) my[i]=max(my[i-1],y[i]);
	int can=n;
	for (int i=n-1;i>=1;i--) if (my[mx[i]]>=can) can=i;
	for (int i=can;i<=n;i++) ans[p[i]]=1;
	for (int i=1;i<=n;i++) putchar(ans[i]+'0');
	putchar('\n');
}

signed main()
{
//	int T=1;
	int T=read();
	while (T--) GreenDay();
	
	return 0;
}