#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define rep(i,s,t) for(int i=(s),__t=(t);i<__t;i++)
#define per(i,s,t) for(int i=(s)-1,__t=(t);i>=__t;i--)
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
#define all(x) ((x).begin(),(x).end())
#define SZ(x) ((int)(x).size())
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef double db;
typedef pair<ll,int> pli;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const db eps=1e-10;
//head
int lowbit(int x){return x&(-x);}
ll powmod(ll x,ll k){ll res=1;for(;k;k>>=1,x=x*x%mod)if(k&1)res=res*x%mod;return res;}
ll gcd(ll a,ll b){return !b?a:gcd(b,a%b);}
template<class T>void Min(T &a,T b){if(a>b)a=b;}
template<class T>void Max(T &a,T b){if(a<b)a=b;}
template<class T>void add(T &a,T b){a+=b;if(a>=mod)a-=mod;}
template<class T>void rd(T &x) {
    static char c;x=0;int f=1;
    while(c=getchar(),c<48)if(c=='-')f=-1;
    do x=(x<<1)+(x<<3)+(c^48);
    while(c=getchar(),c>47);
    x*=f;
}

const int N=1e6+5;
const int M=2e6+5;
ll la,lb,len,tot;
ll c00,c01,c10,c11;// 00 01 10 11
char a[N],b[N];
int A[N],B[N];
ll fac[M],inv[M];

void gmod(ll &x) {x=(x%mod+mod)%mod;}

void prepare() {
	fac[0]=inv[0]=inv[1]=1;
	rep(i,1,M) fac[i]=fac[i-1]*i%mod;
	rep(i,2,M) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
	rep(i,1,M) inv[i]=inv[i-1]*inv[i]%mod;
}
ll C(ll a,ll b) {if(a<0||b<0) return 0;if(a<b) return 0;return fac[a]*inv[b]%mod*inv[a-b]%mod;}
ll calc(ll b,ll a) {if(b==0) return 1;return C(b+a-1,a-1);}

ll solve0(ll c00,ll c01,ll c10,ll c11) {
	if(c00<0||c01<0||c10<0||c11<0) return 0;
	if(c01==c10) return calc(c11,c10)*calc(c00,c01+1)%mod;
	else if (c01==c10+1) return calc(c00,c01)*calc(c11,c10+1)%mod;
	else return 0;
}
ll solve1(ll c00,ll c01,ll c10,ll c11) {
	if(c00<0||c01<0||c10<0||c11<0) return 0;
	if(c01==c10) return calc(c11,c01+1)*calc(c00,c01)%mod;
	else if (c10==c01+1) return calc(c11,c10)*calc(c00,c01+1)%mod;
	else return 0;
}

ll calc1() {
	ll res=0,c0=c00,c1=c01,c2=c10,c3=c11;
	int las=B[0];
	rep(i,1,tot) {
		if(B[i]==1) {
			if(las==0) add(res,solve0(c00-1,c01,c10,c11));
			else add(res,solve0(c00,c01,c10-1,c11));
		}
		if(las==0&&B[i]==1) c01--;
		if(las==0&&B[i]==0) c00--;
		if(las==1&&B[i]==1) c11--;
		if(las==1&&B[i]==0) c10--;
		las=B[i];
	}
	gmod(res);
	if(!c00&&!c01&&!c10&&!c11) add(res,1ll);
	gmod(res);
	c00=c0,c01=c1,c10=c2,c11=c3;
	return res;
}
ll calc2() {
	ll res=0;
	ll c0=c00,c1=c01,c2=c10,c3=c11;
	int las=A[0];
	rep(i,1,tot) {
		if(A[i]==1) {
			if(las==0) add(res,solve0(c00-1,c01,c10,c11));
			else add(res,solve0(c00,c01,c10-1,c11));
		}
		if(las==0&&A[i]==1) c01--;
		if(las==0&&A[i]==0) c00--;
		if(las==1&&A[i]==1) c11--;
		if(las==1&&A[i]==0) c10--;
		las=A[i];
	}
	gmod(res);
	c00=c0,c01=c1,c10=c2,c11=c3;
	return res;
}

int main() {
	prepare();
	scanf("%s%s",a,b);
	la=strlen(a),lb=strlen(b);
	rep(i,0,la) A[i]=a[i]-'0';
	rep(i,0,lb) B[i]=b[i]-'0';
	rd(c00),rd(c01),rd(c10),rd(c11);
	tot=c01+c10+c00+c11+1;
	ll ans=0;
	if(tot>lb) return puts("0"),0;
	else if(tot<lb) ans+=solve1(c00,c01,c10,c11);
	else if(tot==lb) ans+=calc1();
	gmod(ans);
	if(la>tot) return puts("0"),0;
	else if(tot<la) ans-=solve0(c00,c01,c10,c11);
	else if(la==tot) ans-=calc2();
	gmod(ans);
	printf("%lld\n",ans);
	return 0;	
}