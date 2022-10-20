#include<bits/stdc++.h>
#define ll long long
#define piir pair<int,int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int N=1e5+5;
const int inf=1e9+7;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

template<typename T>bool ckmn(T &x,T y){return x>y?(x=y,1):0;}
int a[N],b[N],f[N],from[N];
vector<int>pos[N];
piir g[N];
void get(int x,int val,int p,int len)
{
//	print(x,' '),print(val,' '),print(p,' '),print(len);
	if (!len) return;
	if (~a[x]) return get(from[x],a[x],p,len-1);
	while (b[p]>=val) p--;
	a[x]=b[p],b[p--]=-1;
	for (int i:pos[len-1]) if (i<x&&a[i]<a[x]) return get(i,a[x],p,len-1);
	int tmp=a[x];
	while (~a[x]) x--;
	get(x,tmp,p,len-1);
}

signed main()
{
	int n=read(); for (int i=1;i<=n;i++) a[i]=read();
	int m=read(); for (int i=1;i<=m;i++) b[i]=read();
	sort(b+1,b+1+m),a[++n]=inf;
	for (int i=1;i<=n;i++) g[i]=mk(inf,0);
	for (int i=1;i<=n;i++)
	if (~a[i])
	{
		int tmp=lower_bound(g+1,g+1+n,mk(a[i],0))-g-1;
		f[i]=tmp+1,from[i]=g[tmp].se;
		ckmn(g[f[i]],mk(a[i],i));
		pos[f[i]].push_back(i);
	}
	else
	for (int j=m,k=n;j>=1;j--)
	{
		while (g[k].fi>=b[j]) k--;
		ckmn(g[k+1],mk(b[j],i));
	}
//	print(f[n]-1);
	get(n,inf,m,f[n]);
	for (int i=1,j=1;i<=n;i++)
	if (a[i]<0)
	{
		while (b[j]<0) j++;
		a[i]=b[j++];
	}
	for (int i=1;i<n;i++) print(a[i]," \n"[i+1==n]);
	
	return 0;
}