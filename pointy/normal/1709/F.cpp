// Author: Little09
// Problem: F. Multiset of Strings
// Contest: Educational Codeforces Round 132 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1709/problem/F
// Memory Limit: 512 MB
// Time Limit: 6000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes puts("Yes")
#define printYES puts("YES")
#define printNo puts("No")
#define printNO puts("NO")
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
const ll mod=998244353;
//const ll mod=1000000007;

const int N=200005;
int n,k,f; 
ll dp[20][N],s[20][2*N];

inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
    while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
    while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
    return F*ANS;
}
inline char readchar()
{
	char C=getchar();
    while (C<33||C>126) C=getchar();
    return C;
}
inline int raed(){return read();}

#define pt(a) cout<<a<<endl
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define inf 0x3f3f3f3f
#define eps 1e-10
#define PI acos(-1.0)
typedef pair<int,int> PII;
ll gcd(ll p,ll q){return q==0?p:gcd(q,p%q);}
ll qp(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int to[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
ll A,B,a[N*10],b[N*10],R[N*10],g[N*10],L;
void NTT(ll a[N],int n)
{
    for (int i=0;i<n;i++) if (i<R[i]) swap(a[i],a[R[i]]);
    for (int d=1,t=n>>1;d<n;d<<=1,t>>=1)
        for (int i=0;i<n;i+=(d<<1))
            for (int j=0;j<d;j++){
                ll tmp=g[t*j]*a[i+j+d]%mod;
                a[i+j+d]=(a[i+j]-tmp+mod)%mod;
                a[i+j]=(a[i+j]+tmp)%mod;
            }
}
void mul(int A,int B,int id)
{
	mem(R),mem(g);
	//for (int i=0;i<A;i++) cout << a[i] << " ";
	//cout << endl;
	//for (int i=0;i<B;i++) cout << b[i] << " ";
	//cout << endl;
	ll n;
    for (n=1,L=0;n<=A+B;n<<=1,L++);
    for (int i=0;i<n;i++) R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
	g[0]=1,g[1]=qp(3,(mod-1)/n);
    for (int i=2;i<n;i++) g[i]=g[i-1]*g[1]%mod;
    NTT(a,n),NTT(b,n);
    for (int i=0;i<n;i++) a[i]=a[i]*b[i]%mod;
    g[0]=1,g[1]=qp(g[1],mod-2);
    for (int i=2;i<n;i++) g[i]=g[i-1]*g[1]%mod;
    NTT(a,n);
    ll Inv=qp(n,mod-2);
    for (int i=0;i<n;i++) a[i]=a[i]*Inv%mod;
    for (int i=0;i<=A+B;i++) dp[id][i]=a[i];
    return;
}

int main()
{
	n=read(),k=read(),f=read();
	for (int i=0;i<=k;i++) dp[1][i]=1;
	for (int i=2;i<=n;i++)
	{
		mem(a),mem(b);
		for (int j=0;j<=k;j++) a[j]=dp[i-1][j];
		for (int j=0;j<=k;j++) b[j]=dp[i-1][j];
		mul(k,k,i);
		for (int j=2*k;j>=0;j--) s[i][j]=(dp[i][j]+s[i][j+1])%mod;
		for (int j=2*k-1;j>=0;j--) dp[i][j]=(dp[i][j]*(k-j+1)%mod+s[i][j+1])%mod;
		for (int j=2*k;j>k;j--) dp[i][j]=0;
	}
	ll ans=0;
	for (int i=0;i<=f;i++) ans=(ans+dp[n][i]*dp[n][f-i]%mod)%mod;
	cout << ans << endl;
	return 0;
}