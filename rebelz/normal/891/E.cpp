#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=1000000007;
ll n,k,invn,ans;
ll a[5005],d[5005][5005],prd[5005],pw[5005];

ll mod(ll x){return x>=cys?x-cys:x;}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

int main(){
	n=readint(); k=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=0;i<=n;i++) d[i][0]=1;
	for(int i=1;i<=n;i++) for(int j=1;j<=i;j++) d[i][j]=mod(d[i-1][j]+d[i-1][j-1]*a[i]%cys);
	prd[0]=1;
	for(int i=1;i<=n;i++) prd[i]=prd[i-1]*(k-i+1)%cys;
	invn=qpow(n,cys-2);
	pw[0]=1;
	for(int i=1;i<=n;i++) pw[i]=pw[i-1]*invn%cys;
	for(int i=0;i<=n;i++) ans=mod(ans+pw[i]*prd[i]%cys*(i&1?cys-1:1)%cys*d[n][n-i]%cys);
	cout<<mod(d[n][n]+cys-ans)<<endl;
	return 0;
}