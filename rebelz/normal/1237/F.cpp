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

bool chkmax(int &x,int y){return x<y?x=y,true:false;}
bool chkmin(int &x,int y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=998244353;
ll mod(ll x){return x>=cys?x-cys:x;}

struct node{
	int n;
	ll res[3605];
	node(){n=0;memset(res,0,sizeof(res));}
	node operator*(const node c)const{
		node ret; ret.n=n+c.n;
		for(int i=0;i<=n;i++) for(int j=0;j<=c.n;j++) ret.res[i+j]=mod(ret.res[i+j]+res[i]*c.res[j]%cys);
		return ret;
	}
}ansx,ansy,d[3605];

int n,m,k;
ll fac[3605],inv[3605];
bool vx[3605],vy[3605];

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

int main(){
	n=readint(); m=readint(); k=readint();
	fac[0]=inv[0]=1;
	for(int i=1;i<=max(n,m);i++) fac[i]=fac[i-1]*i%cys;
	inv[max(n,m)]=qpow(fac[max(n,m)],cys-2);
	for(int i=max(n,m)-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%cys;
	int x1,y1,x2,y2;
	vx[0]=vy[0]=vx[n+1]=vy[m+1]=1;
	for(int i=1;i<=k;i++){
		x1=readint(); y1=readint(); x2=readint(); y2=readint();
		vx[x1]=vx[x2]=1,vy[y1]=vy[y2]=1;
	}
	d[0].res[0]=1;
	for(int i=1;i<=max(n,m);i++) d[i].n=i/2;
	for(int i=1;i<=max(n,m);i++) for(int j=0;j<=i/2;j++) d[i].res[j]=mod(d[i-1].res[j]+(i>1&&j?d[i-2].res[j-1]:0));
	int lst=0;
	ansx.res[0]=ansy.res[0]=1;
	for(int i=1;i<=n+1;i++){
		if(vx[i]&&lst!=i-1) ansx=ansx*d[i-lst-1];
		if(vx[i]) lst=i;
	}
	lst=0;
	for(int i=1;i<=m+1;i++){
		if(vy[i]&&lst!=i-1) ansy=ansy*d[i-lst-1];
		if(vy[i]) lst=i;
	}
	int kxn=0,kxm=0;
	for(int i=1;i<=n;i++) if(!vx[i]) kxn++;
	for(int i=1;i<=m;i++) if(!vy[i]) kxm++;
	ll ans=0;
	for(int i=0;i<=kxn;i++){
		for(int j=0;j<=kxm;j++){
			if((i+i-j)%3!=0) continue;
			int ln=(i+i-j)/3,lm=i-2*ln;
			if(lm<0||ln<0) continue;
			ans=mod(ans+ansx.res[ln]*ansy.res[lm]%cys*fac[kxn-2*ln]%cys*inv[kxn-2*ln-lm]%cys*fac[kxm-2*lm]%cys*inv[kxm-2*lm-ln]%cys);
		}
	}
	cout<<ans<<endl;
	return 0;
}