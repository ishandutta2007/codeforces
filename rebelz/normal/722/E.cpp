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

struct node{
	int x,y;
	bool operator<(const node c)const{return x==c.x?y<c.y:x<c.x;}
}a[2005];

const int cys=1000000007;
int n,m,p,s;
ll fac[200005],inv[200005],lst[30],d[2005][30];

ll mod(ll x){return x>=cys?x-cys:x;}
ll C(ll x,ll y){return x<y?0:fac[x]*inv[y]%cys*inv[x-y]%cys;}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

int main(){
	n=readint(); m=readint(); p=readint(); s=readint();
	fac[0]=inv[0]=1;
	for(int i=1;i<=n+m;i++) fac[i]=fac[i-1]*i%cys;
	for(int i=1;i<=n+m;i++) inv[i]=qpow(fac[i],cys-2);
	lst[0]=s;
	for(int i=1;i<=20;i++) lst[i]=(lst[i-1]+1)/2;
	for(int i=1;i<=p;i++) a[i].x=readint(),a[i].y=readint();
	sort(a+1,a+p+1);
	a[p+1].x=n,a[p+1].y=m; p++;
	for(int i=1;i<=p;i++){
		d[i][1]=C(a[i].x+a[i].y-2,a[i].x-1);
		for(int k=1;k<=i-1;k++)
			if(a[k].y<=a[i].y)
				d[i][1]=mod(d[i][1]+cys-C(a[i].x-a[k].x+a[i].y-a[k].y,a[i].x-a[k].x)*d[k][1]%cys);
		for(int j=2;j<=20;j++)
			for(int k=1;k<=i-1;k++)
				if(a[k].y<=a[i].y)
					d[i][j]=mod(d[i][j]+C(a[i].y-a[k].y+a[i].x-a[k].x,a[i].x-a[k].x)*mod(d[k][j-1]+cys-d[k][j])%cys);
		for(int k=1;k<=i-1;k++)
			if(a[k].y<=a[i].y)
				d[i][21]=mod(d[i][21]+C(a[i].y-a[k].y+a[i].x-a[k].x,a[i].x-a[k].x)*d[k][20]%cys);
	}
	ll ans=0;
	for(int i=1;i<=21;i++) ans=mod(ans+d[p][i]*lst[i-1]%cys);
	printf("%lld\n",ans*qpow(C(n+m-2,n-1),cys-2)%cys);
	return 0;
}