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

ll n,p,l,r,cnt,tot,ap,ans;
ll dv[15],du[15],num[15],prm[100005];
bool fl[100005];

ll qpow(ll x,ll p,ll cys){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

namespace Cb{
	ll prd[15][200005];
	void exgcd(ll x,ll y,ll &a,ll &b){
		if(y==0){
			a=1,b=0;
			return;
		}
		exgcd(y,x%y,b,a);
		b-=a*(x/y);
	}
	ll getinv(ll n,ll cys){
		ll x,y;
		exgcd(n,cys,x,y);
//		cout<<"getinv "<<n<<' '<<cys<<' '<<(x%cys+cys)%cys<<endl;
		return (x%cys+cys)%cys;
	}
	ll calc(ll n,ll x){
		if(n<=1) return 1;
		ll ans=n>=du[x]?qpow(prd[x][du[x]],n/du[x],du[x]):1;
//		cout<<"calc "<<n<<' '<<x<<' '<<(n%du[x]==0?ans:ans*prd[x][n%du[x]]%du[x])<<endl;
		return (n%du[x]==0?ans:ans*prd[x][n%du[x]]%du[x])*calc(n/dv[x],x)%du[x];
	}
	ll C(ll n,ll m,ll x){
		ll pw=0;
		for(ll i=n;i;i/=dv[x]) pw+=i/dv[x];
		for(ll i=m;i;i/=dv[x]) pw-=i/dv[x];
		for(ll i=n-m;i;i/=dv[x]) pw-=i/dv[x];
		if(pw>=num[x]) return 0;
		return qpow(dv[x],pw,du[x])*calc(n,x)%du[x]*getinv(calc(m,x),du[x])%du[x]*getinv(calc(n-m,x),du[x])%du[x];
	}
	ll exlucas(ll n,ll m){
		if(n<m) return 0;
		ll now=1,lst=0,aa,nw;
		for(int i=1;i<=cnt;i++){
			aa=C(n,m,i);
			nw=now*du[i];
			lst=(aa*now%nw*getinv(now%du[i],du[i])%nw+lst*du[i]%nw*getinv(du[i]%now,now)%nw)%nw;
			now=nw;
		}
		return lst;
	}
}

void getprime(){
	fl[1]=true;
	for(int i=2;i<=100000;i++){
		if(!fl[i]) prm[++tot]=i;
		for(int j=1;j<=tot&&i*prm[j]<=100000;j++){
			fl[i*prm[j]]=true;
			if(i%prm[j]==0) break;
		}
	}
}

int main(){
	getprime();
	n=readint(); ap=p=readint(); l=readint(); r=readint();
	for(int i=1;i<=tot&&prm[i]<=sqrt(p);i++){
		if(p%prm[i]==0){
			dv[++cnt]=prm[i],du[cnt]=1;
			while(p%prm[i]==0) num[cnt]++,p/=prm[i],du[cnt]*=prm[i];
		}
	}
	if(p>1) dv[++cnt]=p,num[cnt]=1,du[cnt]=p;
	for(int i=1;i<=cnt;i++){
		Cb::prd[i][0]=1;
		for(int j=1;j<=min(n,du[i]);j++){
			Cb::prd[i][j]=Cb::prd[i][j-1];
			if(j%dv[i]) Cb::prd[i][j]=Cb::prd[i][j]*j%du[i];
		}
	}
//	for(int i=1;i<=cnt;i++) cout<<dv[i]<<' '<<num[i]<<' '<<du[i]<<endl;
	for(int i=0;i<=n;i++) ans=(ans+Cb::exlucas(n,i)*(Cb::exlucas(n-i,(n-i+l+1)/2)+ap-Cb::exlucas(n-i,(n-i+r)/2+1))%ap)%ap;
	cout<<ans<<endl;
	return 0;
}