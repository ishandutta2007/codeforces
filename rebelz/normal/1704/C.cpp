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

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=998244353;
int n,m;
int a[1000005],b[1000005];
ll fac[1000005],inv[1000005];

ll mod(ll x){return x>=cys?x-cys:x;}
ll C(ll x,ll y){return x<y?0:fac[x]*inv[y]%cys*inv[x-y]%cys;}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

int main(){
	int T=readint();
	while(T--){
		n=readint(); m=readint();
		for(int i=1;i<=m;i++) a[i]=readint();
		sort(a+1,a+m+1);
		for(int i=1;i<m;i++) b[i]=a[i+1]-a[i]-1;
		b[m]=a[1]+n-a[m]-1;
		sort(b+1,b+m+1);
		reverse(b+1,b+m+1);
		int ans=m;
		for(int i=1;i<=m;i++){
			int x=b[i]-4*(i-1);
			if(x<=0){
				ans+=b[i];
				continue;
			}
			ans+=b[i]-max(1,x-1);
		}
		printf("%d\n",ans);
	}
	return 0;
}