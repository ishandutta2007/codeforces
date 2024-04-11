#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1.5e6+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

char a[N],b[N],s[N];
int f[N],g[N];
void Z(char *a,int n,int *z)
{
	z[1]=n;
	for (int i=2,l=1,r=1;i<=n;i++)
	{
		z[i]=i<=r?min(z[i-l+1],r-i+1):0;
		while (a[1+z[i]]==a[i+z[i]]) z[i]++;
		if (i+z[i]-1>r) l=i,r=i+z[i]-1;
	}
}
void getZ(char *a,char *b,int n,int m,int *f)
{
	static int z[N];
	static char s[N];
	for (int i=1;i<=m;i++) s[i]=b[i];
	s[m+1]='#';
	for (int i=1;i<=n;i++) s[m+1+i]=a[i];
	Z(s,n+m+1,z);
	for (int i=1;i<=n;i++) f[i]=z[m+1+i];
}
struct bit
{
	int tot[N],n;
	ll sum[N];
	void send(int _n){n=_n+1;}
	void add(int x,int y,int z){x++;for (;x;x&=x-1) tot[x]+=y,sum[x]+=y*z;}
	int querytot(int x){int ret=0;x=max(x+1,1);for (;x<=n;x+=x&-x) ret+=tot[x];return ret;}
	ll querysum(int x){ll ret=0;x=max(x+1,1);for (;x<=n;x+=x&-x) ret+=sum[x];return ret;}
}t;

signed main()
{
	int n=read(),m=read();
	scanf("%s%s%s",a+1,b+1,s+1);
	getZ(a,s,n,m,f);
	reverse(b+1,b+1+n);
	reverse(s+1,s+1+m);
	getZ(b,s,n,m,g);
	reverse(g+1,g+1+n);
//	for (int i=1;i<=n;i++) print(f[i]," \n"[i==n]);
//	for (int i=1;i<=n;i++) print(g[i]," \n"[i==n]);
	t.send(n);
	ll ans=0;
	for (int i=1,j=1;i<=n;i++)
	{
		t.add(f[i],1,f[i]-(f[i]==m));
		if (i-j+1==m) t.add(f[j],-1,f[j]-(f[j]==m)),j++;
		ans+=1LL*t.querytot(m-g[i]-1)*(g[i]-m+1-(g[i]==m))+t.querysum(m-g[i]-1);
	}
	print(ans);
	
	return 0;
}