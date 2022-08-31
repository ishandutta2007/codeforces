#include<bits/stdc++.h>

#define y1 dmytxdy
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=998244353;
int n,m,k;
ll a[60],f[60],C[60][60],d[60][60],p[60];

ll mod(ll x){return x>=cys?x-cys:x;}

void dfs(int u,int t,ll x){
	if(u==t) p[__builtin_popcountll(x)]++;
	else dfs(u+1,t,x),dfs(u+1,t,x^f[u]);
}

void insert(ll x){
	for(int i=m-1;i>=0;i--){
		if(x&(1ll<<i)){
			if(a[i]) x^=a[i];
			else{
				a[i]=x;
				return;
			}
		}
	}
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++) insert(readint());
	for(int i=0;i<m;i++)
		if(a[i])
			for(int j=i+1;j<m;j++)
				if((a[j]>>i)&1)
					a[j]^=a[i];
	for(int i=0;i<m;i++){
		if(a[i]){
			if(i!=k){
				for(int j=0;j<m;j++){
					if(!a[j]) continue;
					int ti=(a[j]>>i)&1,tk=(a[j]>>k)&1;
					if(ti) a[j]^=1ll<<i;
					if(tk) a[j]^=1ll<<k;
					if(ti) a[j]^=1ll<<k;
					if(tk) a[j]^=1ll<<i;
				}
			}
			k++;
		}
	}
	k=0;
	for(int i=0;i<m;i++) if(a[i]) f[k++]=a[i];
	for(int i=k;i<m;i++) f[i]=1ll<<i;
	for(int i=k;i<m;i++) for(int j=0;j<k;j++) if((f[j]>>i)&1) f[i]^=1ll<<j;
	if(k<=27){
		dfs(0,k,0);
		ll ans=1;
		for(int i=0;i<n-k;i++) ans=ans*2%cys;
		for(int i=0;i<=m;i++) printf("%lld ",ans*p[i]%cys);
		printf("\n");
	}
	else{
		dfs(k,m,0);
		for(int i=0;i<=m;i++) C[i][0]=1;
		for(int i=1;i<=m;i++) for(int j=1;j<=i;j++) C[i][j]=mod(C[i-1][j]+C[i-1][j-1]);
		for(int i=0;i<=m;i++){
			for(int j=0;j<=m;j++){
				for(int l=0;l<=i;l++){
					ll tmp=C[j][l]*C[m-j][i-l]%cys;
					if(l&1) d[i][j]=mod(d[i][j]+cys-tmp);
					else d[i][j]=mod(d[i][j]+tmp);
				}
			}
		}
		for(int i=0;i<=m;i++){
			ll ans=0;
			for(int j=0;j<=m;j++) ans=(ans+p[j]*d[i][j])%cys;
			for(int j=0;j<m-k;j++) ans=ans*((cys+1)/2)%cys;
			for(int j=0;j<n-k;j++) ans=ans*2%cys;
			printf("%lld ",ans);
		}
		printf("\n");
	}
	return 0;
}