#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

bool ans[N];
int x[N],p[N],pos[N*3],Log[N*3];
ll c[N*3],k[N*3],b[N*3],mx[N*3];
ll st[20][N*3];
ll query(int l,int r)
{
	int k=Log[r-l+1];
	return max(st[k][l],st[k][r-(1<<k)+1]);
}
void work()
{
	int n=read(),m=read(),cnt=0;
	for (int i=1;i<=n;i++) x[i]=read(),p[i]=read();
	for (int i=1;i<=n;i++) pos[++cnt]=x[i]-p[i],pos[++cnt]=x[i],pos[++cnt]=x[i]+p[i];
	sort(pos+1,pos+1+cnt);
	for (int i=1;i<=cnt;i++) c[i]=0;
	for (int i=1;i<=n;i++)
	{
		c[lower_bound(pos+1,pos+1+cnt,x[i]-p[i])-pos]++;
		c[lower_bound(pos+1,pos+1+cnt,x[i])-pos]-=2;
		c[lower_bound(pos+1,pos+1+cnt,x[i]+p[i])-pos]++;
	}
	ll sum=0,now=0;
	for (int i=1;i<cnt;i++)
	{
		sum+=c[i];
		k[i]=sum;
		b[i]=now;
		now+=(pos[i+1]-pos[i])*sum;
//		print(pos[i],':'),print(k[i],' '),print(b[i]);
	}
	for (int i=2;i<cnt;i++) Log[i]=Log[i/2]+1;
	for (int i=1;i<cnt;i++) mx[i]=b[i]+max(k[i],0LL)*(pos[i+1]-pos[i]);
	for (int i=1;i<cnt;i++) mx[i]=max(mx[i],mx[i-1]);
	for (int i=1;i<cnt;i++) st[0][i]=b[i]+max(k[i]-1,0LL)*(pos[i+1]-pos[i])-pos[i];
	for (int j=1;j<20;j++)
	for (int i=1;i+(1<<j)-1<cnt;i++)
	st[j][i]=max(st[j-1][i],st[j-1][i+(1<<(j-1))]);
	for (int i=1;i<=n;i++)
	{
		int L=lower_bound(pos+1,pos+1+cnt,x[i]-p[i])-pos;
		int M=lower_bound(pos+1,pos+1+cnt,x[i])-pos;
		ans[i]=mx[L-1]<=m&&query(L,M-1)-p[i]+x[i]<=m;
	}
//	for (int i=1;i<=n;i++) putchar(ans[i]+'0');
//	putchar('\n');
	mx[cnt]=0;
	for (int i=1;i<cnt;i++) mx[i]=b[i]+max(k[i],0LL)*(pos[i+1]-pos[i]);
	for (int i=cnt-1;i>=1;i--) mx[i]=max(mx[i],mx[i+1]);
	for (int i=1;i<cnt;i++) st[0][i]=b[i]+max(k[i]+1,0LL)*(pos[i+1]-pos[i])+pos[i];
	for (int j=1;j<20;j++)
	for (int i=1;i+(1<<j)-1<cnt;i++)
	st[j][i]=max(st[j-1][i],st[j-1][i+(1<<(j-1))]);
	for (int i=1;i<=n;i++)
	{
		int M=lower_bound(pos+1,pos+1+cnt,x[i])-pos;
		int R=lower_bound(pos+1,pos+1+cnt,x[i]+p[i])-pos;
		ans[i]&=mx[R]<=m&&query(M,R-1)-p[i]-x[i]<=m;
//		print(M,','),print(R,' ');
//		print(query(M,R-1));
	}
	for (int i=1;i<=n;i++) putchar(ans[i]+'0');
	putchar('\n');
}

signed main()
{
	int T=read();
	while (T--) work();
	
	return 0;
}