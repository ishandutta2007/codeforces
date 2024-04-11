#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int inf=1e18; 
const int M=1e5+10;
const int N=sqrt(M)+10;
const int B=20;
int n,dp[B][M],s1[N][M],s2[N][M],prime[M],phi[M],s[M],f[M],tot;

int work(int l,int r)
{
	int L=r/(r/l),res=(L-l+1)*(s[r/l]);
	l=L+1;if (l>r)return res;
	if (l*l<=r)return res+s1[l][r];
	else return res+s2[r/l][r];
}

void solve(int k,int l,int r,int L,int R)
{
	if (l>r)return;
	int Mid=(l+r)>>1,pos=-1,res=inf;
	for (int i=L;i<=min(R,Mid);i++)
	{
		int tmp=dp[k-1][i-1]+work(i,Mid);
		if (tmp<res)res=tmp,pos=i;
	}dp[k][Mid]=res;
	solve(k,l,Mid-1,L,pos),solve(k,Mid+1,r,pos,R);
}

void init(int n)
{
	phi[1]=1;
	for (int i=2;i<=n;i++)
	{
		if (!f[i])prime[++tot]=i,phi[i]=i-1;
		for (int j=1;j<=tot&&prime[j]*i<=n;j++)
		{
			f[i*prime[j]]=1;phi[i*prime[j]]=phi[i]*(prime[j]-1);
			if (i%prime[j]==0){phi[i*prime[j]]=phi[i]*prime[j];break;}
		}
	}
	for (int i=1;i<=n;i++)s[i]=s[i-1]+phi[i];
	for (int i=1;i<=n;i++)
	{
		int sum=i*(i+1)/2;
		for (int l=1,r=0;l<=i;l=r+1)
		{
			r=i/(i/l);
			if (l*l<=i)s1[l][i]=sum;
			else s2[i/l][i]=sum;
			sum-=(r-l+1)*s[i/l];
		}
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	for (int i=1;i<=18;i++)solve(i,i,n,i,n); 
}

void solve()
{
	int n=read(),k=read();
	if (k>18)cout<<n<<'\n';
	else cout<<dp[k][n]<<'\n';
}

signed main()
{
	init(1e5);
	WT solve();
	return 0;
}