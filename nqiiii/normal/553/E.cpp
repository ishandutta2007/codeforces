#pragma GCC optimize(3)
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=50,maxm=100,maxt=20000;
const double inf=1e10,pi=acos(-1);
struct cd{double x,y;};
cd operator+(const cd &a,const cd &b){return (cd){a.x+b.x,a.y+b.y};}
cd operator-(const cd &a,const cd &b){return (cd){a.x-b.x,a.y-b.y};}
cd operator*(const cd &a,const cd &b){return (cd){a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x};}
int n,m,t,x,l[maxm+10],r[maxm+10],ll,lgl,rv[maxt*4+10];
double c[maxm+10],p[maxm+10][maxt+10];
double f[maxm+10][maxt+10],h[maxn+10][maxt+10];
double tmp[maxt+10];
cd a[maxt*4+10],b[maxt*4+10],wn[maxt*4+10];
void init(){
	for(int i=1;i<n;++i) for(int j=0;j<=t+1;++j) h[i][j]=inf;
	h[n][t+1]=x;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			h[l[j]][t+1]=min(h[l[j]][t+1],h[r[j]][t+1]+c[j]);
	for(int i=1;i<=m;++i){
		tmp[t+1]=0;
		for(int j=t;j>=1;--j) tmp[j]=tmp[j+1]+p[i][j];
		for(int j=1;j<=t;++j) f[i][j]+=h[r[i]][t+1]*tmp[t+1-j];
	}
}
void dft(cd *a){
	for(int i=0;i<ll;++i) if(i<rv[i]) swap(a[i],a[rv[i]]);
	for(int i=1;i<ll;i<<=1)
		for(int j=0;j<ll;j+=i<<1)
			for(int k=0;k<i;++k){
				cd x=a[j+k],y=wn[k*(ll/i)]*a[i+j+k];
				a[j+k]=x+y; a[i+j+k]=x-y;
			}
}
void solve(int ls,int rs){
	if(ls==rs){
		for(int i=1;i<=m;++i) 
			h[l[i]][ls]=min(h[l[i]][ls],f[i][ls]+c[i]);
		return;
	}
	int mid=(ls+rs)/2; solve(mid+1,rs);
	for(int i=1;i<=m;++i){
		int shift=rs-ls-mid-1;
		for(ll=1,lgl=-1;ll<=rs*2-mid-2-ls;ll<<=1) ++lgl;
		for(int j=0;j<ll;++j){
			a[j]=b[j]=wn[j]=(cd){0,0}; rv[j]=0;
			rv[j]=rv[j>>1]>>1|(j&1)<<lgl;
			wn[j]=(cd){cos(j*pi/ll),sin(j*pi/ll)};
		}
		for(int j=mid+1;j<=rs;++j) a[j-mid-1]=(cd){h[r[i]][j],0};
		for(int j=1;j<=rs-ls;++j) b[-j+rs-ls]=(cd){p[i][j],0};
		dft(a); dft(b); for(int i=0;i<ll;++i) a[i]=a[i]*b[i];
		reverse(a+1,a+ll); dft(a);
		for(int j=ls;j<=mid;++j) f[i][j]+=a[j+shift].x/ll;
	}
	solve(ls,mid);
}
int main(){
	scanf("%d%d%d%d",&n,&m,&t,&x);
	for(int i=1;i<=m;++i){
		scanf("%d%d%lf",&l[i],&r[i],&c[i]);
		for(int j=1;j<=t;++j) scanf("%lf",&p[i][j]),p[i][j]/=100000;
	}
	init(); solve(0,t);
	printf("%.10lf",h[1][0]);
}