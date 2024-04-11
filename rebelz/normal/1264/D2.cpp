#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=998244353;
int n;
ll fac[1000005],inv[1000005],a1[1000005],a2[1000005],lc[1000005],rc[1000005];
char s[1000005];

ll mod(ll x){return x>=cys?x-cys:x;}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

int main(){
	scanf("%s",s+1); n=strlen(s+1);
	fac[0]=inv[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%cys;
	inv[n]=qpow(fac[n],cys-2);
	for(int i=n-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%cys;
	ll cnt=0;
	for(int i=1;i<=n;i++) if(s[i]=='?') cnt++;
	for(int i=0;i<=cnt;i++) a1[i]=fac[cnt]*inv[i]%cys*inv[cnt-i]%cys;
	for(int i=1;i<=cnt;i++) a1[i]=mod(a1[i]+a1[i-1]);
	for(int i=0;i<cnt;i++) a2[i]=fac[cnt-1]*inv[i]%cys*inv[cnt-1-i]%cys;
	for(int i=1;i<cnt;i++) a2[i]=mod(a2[i]+a2[i-1]);
	for(int i=1;i<=n;i++) lc[i]=lc[i-1]+(s[i]=='(');
	for(int i=n;i>=1;i--) rc[i]=rc[i+1]+(s[i]==')');
	ll lcnt=0,ans=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='?'){
			if(lc[i-1]-rc[i+1]+lcnt<0) ans=mod(ans+a2[cnt-1]);
			else ans=(ans+a2[cnt-1]+cys-a2[min(cnt-1,lc[i-1]-rc[i+1]+lcnt)])%cys;
		}
		else if(s[i]=='('){
			if(lc[i-1]-rc[i+1]+lcnt<0) ans=mod(ans+a1[cnt]);
			else ans=(ans+a1[cnt]+cys-a1[min(cnt,lc[i-1]-rc[i+1]+lcnt)])%cys;
		}
		if(s[i]=='?') lcnt++;
	}
	printf("%lld\n",ans);
	return 0;
}