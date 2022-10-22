#include<bits/stdc++.h>
#define int long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
using namespace std;
int a[200005],n,q;
int val[3][3];
double x,y;
//0,1/y,1/(x+y)
struct matrix {
	double num[3][3];
	void init(int t){
		rep(i,0,3)rep(j,0,3)num[i][j]=0;
		num[1][1]=t/y;num[2][2]=t/(x+y);
	}
}p[1<<19];
matrix emp; 
matrix operator *(matrix x,matrix y){
	matrix re=emp;
	rep(l1,0,3)rep(r1,0,3)rep(l2,0,3)if(val[r1][l2])rep(r2,0,3){
		gmax(re.num[l1][r2],x.num[l1][r1]+y.num[l2][r2]);
	}
	RE re;
}
void build(int x,int l,int r){
	if(l==r){
		p[x].init(a[l]);RE;
	}
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	p[x]=p[lc]*p[rc];
}
void update(int x,int l,int r,int it,int val){
	if(l==r){
		p[x].init(val);RE;
	}
	int mid=(l+r)>>1;
	if(mid>=it)update(lc,l,mid,it,val);
	else update(rc,mid+1,r,it,val);
	p[x]=p[lc]*p[rc];
}
matrix get(int x,int l,int r,int tl,int tr){
	if(l>=tl&&r<=tr)RE p[x];
	int mid=(l+r)>>1;
	if(mid>=tr)RE get(lc,l,mid,tl,tr);
	else if(mid+1<=tl)RE get(rc,mid+1,r,tl,tr);
	else RE get(lc,l,mid,tl,tr)*get(rc,mid+1,r,tl,tr);
}
signed main(){
	val[0][0]=val[0][2]=val[2][0]=val[2][2]=val[0][1]=val[1][0]=1;
	cin>>n>>q>>x>>y;
	if(x>y)swap(x,y);
	FOR(i,1,n)cin>>a[i];
	build(1,1,n);
	FOR(_,1,q){
		int tap,l,r;
		cin>>tap>>l>>r;
		if(tap==1){
			update(1,1,n,l,r);
		}else{
			matrix now=get(1,1,n,l,r);
			double ans=0;
			rep(i,0,3)rep(j,0,3)gmax(ans,now.num[i][j]);
			printf("%.10f\n",ans);
		}
	}
	RE 0;
}