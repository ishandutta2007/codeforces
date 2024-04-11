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
int n,m;
char s[200005];
ll fac[200005],inv[200005];

ll mod(ll x){return x>=cys?x-cys:x;}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}


int main(){
	n=readint(); m=readint();
	if(n&1) return printf("0\n"),0;
	scanf("%s",s+1);
	for(int i=1;i<=n;i+=2){
		if(s[i]=='w') s[i]='b';
		else if(s[i]=='b') s[i]='w';
	}
	int cnt1=0,cnt2=0,cnt3=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='w') cnt1++;
		else if(s[i]=='b') cnt2++;
		else cnt3++;
	}
	fac[0]=inv[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%cys;
	inv[n]=qpow(fac[n],cys-2);
	for(int i=n-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%cys;
	ll all=qpow(2,cnt3+1),ans=0;
	for(int i=0;i<=cnt3;i++)
		if(abs((cnt1+i)-(cnt2+cnt3-i))%4==0)
			ans=(ans+abs((cnt1+i)-(cnt2+cnt3-i))*fac[cnt3]%cys*inv[i]%cys*inv[cnt3-i])%cys;
	printf("%lld\n",ans*qpow(all,cys-2)%cys);
	return 0;
}