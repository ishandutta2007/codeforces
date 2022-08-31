// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<ll> vi;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,cys;
ll pw[85],C[85][85],f[85][85],d[85][85];

ll mod(ll x){return x>=cys?x-cys:x;}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

int main(){
	n=readint(); m=readint(); cys=readint();
	pw[0]=1;
	for(int i=1;i<=max(n,m);i++) pw[i]=pw[i-1]*2%cys;
	for(int i=0;i<=max(n,m);i++) C[i][0]=1;
	for(int i=1;i<=max(n,m);i++)
		for(int j=1;j<=i;j++)
			C[i][j]=mod(C[i-1][j]+C[i-1][j-1]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=0;k<=j;k++){
				ll tmp=C[j][k];
				for(int l=1;l<=i;l++) tmp=tmp*(pw[j-k]-l)%cys;
				if(k&1) f[i][j]=mod(f[i][j]+cys-tmp);
				else f[i][j]=mod(f[i][j]+tmp);
			}
		}
	}
	for(int i=0;i<=n;i++) d[i][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			d[i][j]=qpow(pw[i]-1,j);
			for(int k=1;k<=i;k++){
				for(int l=1;l<=j;l++){
					ll tmp=d[i-k][j-l]*f[k][l]%cys*C[i][k]%cys*C[j][l]%cys*qpow(pw[j-l],k)%cys;
					d[i][j]=mod(d[i][j]+cys-tmp);
				}
			}
		}
	}
	ll ans=0;
	for(int i=0;i<=m;i++) ans=(ans+d[n][i]*C[m][i])%cys;
	if(n&1){
		for(int i=0;i<=m;i++) ans=(ans+n*d[n-1][i]%cys*(pw[m-i]-1)%cys*pw[i]%cys*C[m][i])%cys;
	}
	printf("%lld\n",ans);
	return 0;
}