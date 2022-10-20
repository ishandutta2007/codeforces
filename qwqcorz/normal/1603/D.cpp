#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
bool up(int &x,int y){if (x>y) return x=y,1;return 0;}
vector<int>fac[N];
int phi[N],sum[N],ql=1,qr=1,ans=1;
int calcl(int l){return sum[qr/l];}
int calcr(int r)
{
	int ret=0;
	for (int d:fac[r])
	if (d>=ql) ret+=phi[r/d];
		  else break;
	return ret;
}
int cost(int l,int r)
{
	while (qr<r) ans+=calcr(++qr);
	while (ql>l) ans+=calcl(--ql);
	while (qr>r) ans-=calcr(qr--);
	while (ql<l) ans-=calcl(ql++);
	return ans;
}
int dp[20][N];
void solve(int k,int l,int r,int ql,int qr)
{
	if (l>r) return;
//	print(k,' '),print(l,' '),print(r,':'),print(ql,' '),print(qr);
	int mid=(l+r)/2,now=ql;
	for (int i=ql;i<min(mid,qr);i++) if (up(dp[k][mid],dp[k-1][i]+cost(i+1,mid))) now=i;
	solve(k,l,mid-1,ql,now+1);
	solve(k,mid+1,r,now,qr);
}
void ysgs(int n)
{
	for (int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+(phi[i]+=i);
		for (int j=i+i;j<=n;j+=i) phi[j]-=phi[i];
	}
	for (int i=n;i>=1;i--)
	for (int j=i;j<=n;j+=i) fac[j].push_back(i);
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	for (int k=1;k<20;k++) solve(k,1,n,0,n);
}

signed main(signed Hello,char *CodeForces[])
{
	(void)Hello,(void)CodeForces;
	ysgs(1e5);
	int T=read();
	while (T--)
	{
		int n=read(),k=read();
		if (k>=20) print(n);
			  else print(dp[k][n]);
	}
	
	return 0;
}