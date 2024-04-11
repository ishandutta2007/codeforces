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
char a[1000005],b[1000005];
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
		scanf("%s%s",a+1,b+1);
		bool fl=0;
		for(int i=2;i<=m;i++) if(b[i]!=a[i+n-m]) fl=1;
		if(fl){
			printf("NO\n");
			continue;
		}
		if(n==m){
			if(a[1]==b[1]) printf("YES\n");
			else printf("NO\n");
			continue;
		}
		int now=a[1]-'0';;
		for(int i=1;i<=n-m;i++){
			if(now==-1) continue;
			if(now!=a[i+1]-'0') now=-1;
		}
		if(now==-1||now==b[1]-'0') printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}