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

int n,q; ll x,y;
ll sum[600000],maxa[600000][3][3],ans[3],tmp[3],a[200005];

void update(int id,int l,int r){
	sum[id]=sum[id<<1]+sum[id<<1|1];
	int mid=(l+r)/2;
	for(int i=0;i<3;i++) for(int j=0;j<3;j++) maxa[id][i][j]=-(1ll<<60);
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
				for(int t=0;t<3;t++){
					if(j==1&&k==1) continue;
					ll val=maxa[id<<1][i][j]+maxa[id<<1|1][k][t];
					if(j==2&&k==1) val-=1ll*a[mid]*y;
					if(j==1&&k==2) val-=1ll*a[mid+1]*y;
					int ti=i,tl=t;
					if(mid-l+1==1&&i==2&&k==1) ti=0;
					if(r-mid==1&&t==2&&j==1) tl=0;
					chkmax(maxa[id][ti][tl],val);
				}
			}
		}
	}
}

void build(int id,int l,int r){
	for(int i=0;i<3;i++) for(int j=0;j<3;j++) maxa[id][i][j]=-(1ll<<60);
	if(l==r) return (void)(maxa[id][2][2]=0,maxa[id][1][1]=1ll*a[l]*x,sum[id]=a[l]);
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	update(id,l,r);
}

void change(int id,int l,int r,int p,int c){
	if(l==r) return (void)(maxa[id][1][1]=1ll*c*x,sum[id]=c);
	int mid=(l+r)/2;
	if(p<=mid) change(id<<1,l,mid,p,c);
	else change(id<<1|1,mid+1,r,p,c);
	update(id,l,r);
}

void query(int id,int l,int r,int ql,int qr,int &lst,ll &all){
	if(l==ql&&r==qr){
		all+=sum[id];
		for(int i=0;i<3;i++) tmp[i]=-(1ll<<60);
		for(int k=0;k<3;k++){
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					if(k==1&&i==1) continue;
					ll val=ans[k]+maxa[id][i][j];
					if(k==2&&i==1) val-=1ll*lst*y;
					if(k==1&&i==2) val-=1ll*a[l]*y;
					int tj=j;
					if(l==r&&j==2&&k==1) tj=0;
					chkmax(tmp[tj],val);
				}
			}
		}
		for(int i=0;i<3;i++) ans[i]=tmp[i];
		lst=a[r];
		return;
	}
	int mid=(l+r)/2;
	if(qr<=mid) query(id<<1,l,mid,ql,qr,lst,all);
	else if(ql>mid) query(id<<1|1,mid+1,r,ql,qr,lst,all);
	else query(id<<1,l,mid,ql,mid,lst,all),query(id<<1|1,mid+1,r,mid+1,qr,lst,all);
}

int main(){
	n=readint(); q=readint(); x=readint(); y=readint();
	if(x>y) swap(x,y);
	for(int i=1;i<=n;i++) a[i]=readint();
	build(1,1,n);
	int opt,l,r;
	while(q--){
		opt=readint(); l=readint(); r=readint();
		if(opt==1) a[l]=r,change(1,1,n,l,r);
		else{
			int lst=0; ll all=0;
			for(int i=0;i<3;i++) ans[i]=-(1ll<<60);
			ans[0]=0;
			query(1,1,n,l,r,lst,all);
			ll res=-(1ll<<60);
			for(int i=0;i<3;i++) chkmax(res,ans[i]);
			printf("%.12lf\n",1.0*(1.0*res/y+all)/(x+y));
		}
	}
	return 0;
}