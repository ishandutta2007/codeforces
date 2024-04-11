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

const int cys=998244353;
int n,m;
ll s1,s2,s;
ll a[200005],b[200005],d[55][55][55];

ll mod(ll x){return x>=cys?x-cys:x;}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++) b[i]=readint(),s=mod(s+b[i]);
	for(int i=1;i<=n;i++){
		if(a[i]) s2+=b[i];
		else s1+=b[i];
	}
	for(int i=1;i<=n;i++){
		memset(d,0,sizeof(d));
		d[0][0][0]=1;
		if(a[i]==1){
			for(int j=1;j<=m;j++){
				for(int k=0;k<=j;k++){
					for(int l=0;l<=j;l++){
						if(k>=1&&l>=1) d[j][k][l]=d[j-1][k-1][l-1]*(b[i]+k-1)%cys*qpow(s+l-1-(j-l),cys-2)%cys;
						if(l>=1) d[j][k][l]=mod(d[j][k][l]+d[j-1][k][l-1]*(s2-(b[i]+k)+l-1)%cys*qpow(s+l-1-(j-l),cys-2)%cys);
						d[j][k][l]=mod(d[j][k][l]+d[j-1][k][l]*(s1-(j-1-l))%cys*qpow(s+l-(j-1-l),cys-2)%cys);
					}
				}
			}
			ll ans=0;
			for(int j=0;j<=m;j++) for(int k=0;k<=m;k++) ans=mod(ans+d[m][j][k]*(b[i]+j)%cys);
			printf("%lld\n",ans);
		}
		else{
			for(int j=1;j<=m;j++){
				for(int k=0;k<=j;k++){
					for(int l=0;l<=j;l++){
						if(k>=1&&l>=1) d[j][k][l]=d[j-1][k-1][l-1]*(b[i]-k+1)%cys*qpow(s-l+1+(j-l),cys-2)%cys;
						if(l>=1) d[j][k][l]=mod(d[j][k][l]+d[j-1][k][l-1]*(s1-(b[i]-k)-l+1)%cys*qpow(s-l+1+(j-l),cys-2)%cys);
						d[j][k][l]=mod(d[j][k][l]+d[j-1][k][l]*(s2+(j-1-l))%cys*qpow(s-l+(j-1-l),cys-2)%cys);
					}
				}
			}
			ll ans=0;
			for(int j=0;j<=m;j++) for(int k=0;k<=m;k++) ans=mod(ans+d[m][j][k]*mod(b[i]+cys-j)%cys);
			printf("%lld\n",ans);
		}
	}
	return 0;
}