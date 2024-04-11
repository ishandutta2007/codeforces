#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=55;
const int p=998244353;

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
inline void add(int &x,int y){x+=y;if (x>=p) x-=p;}
int dp[N][N*3],a[N],b[N*3],A[N],ans=0;
int Ca[N][N],inv[N];
int C(int n,int m)
{
	if (n<m||n<0||m<0) return 0;
	if (n<=50) return Ca[n][m];
	int ret=1;
	for (int i=1;i<=m;i++) ret=1LL*ret*(n-i+1)%p*inv[i]%p;
//	print(n,','),print(m,':'),print(ret);
	return ret;
}
int calc(int t1,int t2,int len)
{
	int ret=0;
	for (int i=0;i<=t2;i++)
	ret=(ret+1LL*C(t2,i)*C(len-i+t1-1,t1-1))%p;
//	print(t1,' '),print(t2,' '),print(len,':'),print(ret);
	return ret;
}
int solve(int l,int r)
{
	for (int i=l;i<=r;i++) if (a[i]==a[l]) dp[i][a[l]]=1;
	for (int i=l+1;i<=r;i++)
	for (int j=min(A[i-1],a[i]);j<=max(A[i-1],a[i]);j++)
	{
		int t1=0,t2=0,len=b[j+1]-b[j]-1;
		if (a[i-1]<a[i])
		{
			t1=1;
			if (dp[i][j-1]) add(dp[i][j],1LL*dp[i][j-1]*calc(t1,t2,len)%p);
		}
		for (int k=i-1;k>=l;k--)
		{
			if (a[k-1]<a[k])
			if (min(A[k-1],a[k])<=j&&j<=max(A[k-1],a[k])) t1++;
			if (dp[k][j-1]) add(dp[i][j],1LL*dp[k][j-1]*calc(t1,t2,len)%p);
			if (a[k-1]>a[k])
			if (min(A[k-1],a[k])<=j&&j<=max(A[k-1],a[k])) t2++;
		}
	}
	int ret=0;
	for (int i=l;i<=r;i++)
	if (a[i]==a[r]) add(ret,dp[i][a[r]]);
	return ret;
}
/*
5 0
80 -50 30 -40 60
*/
inline bool check(int n)
{
	for (int i=1;i<=n;i++) if (a[i-1]<a[i]) return 0;
	return 1;
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	inv[0]=inv[1]=1;
	for (int i=2;i<=50;i++) inv[i]=1LL*inv[p%i]*(p-p/i)%p;
	for (int i=Ca[0][0]=1;i<=50;i++)
	for (int j=Ca[i][0]=1;j<=i;j++) Ca[i][j]=(Ca[i-1][j-1]+Ca[i-1][j])%p;
	int n=read(),x=read(),Max=0; (void)x;
	for (int i=1;i<=n;i++) a[i]=a[i-1]+read();
	for (int i=1;i<n;i++)
	if (a[i]==a[i+1])
	{
		for (int j=i;j<n;j++) a[j]=a[j+1];
		n--;
		i--;
	}
	for (int i=0;i<=n;i++)
	for (int j=i;j<=n;j++)
	Max=max(Max,a[j]-a[i]+1);
	if (check(n)) return print(Max,' '),print((-a[n]+1)%p),0;
	int cnt=0;
	for (int i=0;i<n;i++)
	if (a[i]<a[i+1]) b[++cnt]=A[i]=a[i]+1;
				else b[++cnt]=A[i]=a[i]-1;
	for (int i=0;i<=n;i++) b[++cnt]=a[i];
	for (int i=1;i<=n;i++) b[++cnt]=a[i]+1;
	sort(b+1,b+cnt+1);
	cnt=unique(b+1,b+cnt+1)-b-1;
	for (int i=0;i<=n;i++) a[i]=lower_bound(b+1,b+1+cnt,a[i])-b;
	for (int i=0;i<n;i++) A[i]=lower_bound(b+1,b+1+cnt,A[i])-b;
	for (int i=0;i<=n;i++)
	{
		int r=-1;
		for (int j=i;j<=n;j++)
		if (b[a[j]]-b[a[i]]+1==Max) r=j;
		if (~r) add(ans,solve(i,r)),i=r;
	}
	print(Max,' '),print(ans);
//	print(cnt);
//	for (int i=1;i<=cnt;i++) print(b[i]);
//	for (int i=0;i<=n;i++,puts(""))
//	for (int j=1;j<=cnt;j++) print(dp[i][j],' ');
	
	return 0;
}