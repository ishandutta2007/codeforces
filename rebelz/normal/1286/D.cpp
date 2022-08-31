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
typedef long double Ld;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=998244353;

struct node{
	int pl,ld,rd;
	Ld cp;
	ll val;
	node(int pl=0,int ld=0,int rd=0,Ld cp=0,ll val=0):pl(pl),ld(ld),rd(rd),cp(cp),val(val){}
	bool operator<(const node c)const{return cp<c.cp;}
}a[200005];

struct matrix{
	ll c[2][2];
	matrix(){memset(c,0,sizeof(c));}
	matrix operator*(const matrix t)const{
		matrix ret;
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				for(int k=0;k<2;k++)
					ret.c[i][j]=(ret.c[i][j]+c[i][k]*t.c[k][j])%cys;
		return ret;
	}
}tlf[300000],trg[300000];

int n,m;
ll x[100005],v[100005],p[100005];

ll mod(ll x){return x>=cys?x-cys:x;}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

void build(int id,int l,int r){
	if(l==r){
		tlf[id].c[0][0]=tlf[id].c[1][0]=mod(cys+1-p[l]),tlf[id].c[0][1]=tlf[id].c[1][1]=p[l];
		trg[id].c[0][0]=trg[id].c[1][0]=mod(cys+1-p[l]),trg[id].c[0][1]=trg[id].c[1][1]=p[l];
		return;
	}
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	tlf[id]=tlf[id<<1]*tlf[id<<1|1];
	trg[id]=trg[id<<1|1]*trg[id<<1];
}

void changelf(int id,int l,int r,int x,int ld,int rd){
	if(l==r) return (void)(tlf[id].c[ld][rd]=0);
	int mid=(l+r)/2;
	if(x<=mid) changelf(id<<1,l,mid,x,ld,rd);
	else changelf(id<<1|1,mid+1,r,x,ld,rd);
	tlf[id]=tlf[id<<1]*tlf[id<<1|1];
}

void changerg(int id,int l,int r,int x,int ld,int rd){
	if(l==r) return (void)(trg[id].c[rd][ld]=0);
	int mid=(l+r)/2;
	if(x<=mid) changerg(id<<1,l,mid,x,ld,rd);
	else changerg(id<<1|1,mid+1,r,x,ld,rd);
	trg[id]=trg[id<<1|1]*trg[id<<1];
}

matrix querylf(int id,int l,int r,int ql,int qr){
	if(l==ql&&r==qr) return tlf[id];
	int mid=(l+r)/2;
	if(qr<=mid) return querylf(id<<1,l,mid,ql,qr);
	else if(ql>mid) return querylf(id<<1|1,mid+1,r,ql,qr);
	else return querylf(id<<1,l,mid,ql,mid)*querylf(id<<1|1,mid+1,r,mid+1,qr);
}

matrix queryrg(int id,int l,int r,int ql,int qr){
	if(l==ql&&r==qr) return trg[id];
	int mid=(l+r)/2;
	if(qr<=mid) return queryrg(id<<1,l,mid,ql,qr);
	else if(ql>mid) return queryrg(id<<1|1,mid+1,r,ql,qr);
	else return queryrg(id<<1|1,mid+1,r,mid+1,qr)*queryrg(id<<1,l,mid,ql,mid);
}

int main(){
	n=readint();
	ll inv100=qpow(100,cys-2);
	for(int i=1;i<=n;i++) x[i]=readint(),v[i]=readint(),p[i]=readint()*inv100%cys;
	build(1,1,n);
	for(int i=1;i<n;i++){
		a[++m]=node(i+1,1,0,(Ld)(x[i+1]-x[i])/(v[i]+v[i+1]),(x[i+1]-x[i])*qpow(v[i]+v[i+1],cys-2)%cys);
		if(v[i]>v[i+1]) a[++m]=node(i+1,1,1,(Ld)(x[i+1]-x[i])/(v[i]-v[i+1]),(x[i+1]-x[i])*qpow(v[i]-v[i+1],cys-2)%cys);
		else if(v[i]<v[i+1]) a[++m]=node(i+1,0,0,(Ld)(x[i+1]-x[i])/(v[i+1]-v[i]),(x[i+1]-x[i])*qpow(v[i+1]-v[i],cys-2)%cys);
	}
	sort(a+1,a+m+1);
	ll ans=0,inv4=qpow(4,cys-2);
	for(int i=1;i<=m;i++){
		matrix lf=querylf(1,1,n,1,a[i].pl-1),rg=queryrg(1,1,n,a[i].pl,n);
		ans=(ans+(lf.c[0][a[i].ld]+lf.c[1][a[i].ld])*(rg.c[0][a[i].rd]+rg.c[1][a[i].rd])%cys*a[i].val%cys*inv4)%cys;
		changelf(1,1,n,a[i].pl,a[i].ld,a[i].rd);
		changerg(1,1,n,a[i].pl-1,a[i].ld,a[i].rd);
	}
	printf("%lld\n",ans);
	return 0;
}