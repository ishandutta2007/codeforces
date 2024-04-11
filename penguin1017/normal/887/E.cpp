#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
using namespace std;
const int N=1e5+9;
const ll mod=998244353;
const double eps=1e-6;
pair<double,double> getrt(double a,double b,double c){
	double Sqr=b*b-4*a*c;
	//cout<<a<<' '<<b<<' '<<c<<' '<<Sqr<<"check\n";
	double sqr=sqrt(Sqr);
	double l=(-b+sqr)/(2*a),r=(-b-sqr)/(2*a);
	if(l>r+eps)swap(l,r);
	//cout<<l<<' '<<r<<"res\n";
	return {l,r}; 
}
double ld[3],ld2[3],x0,y0;
int xa,ya,xb,yb,x[N],y[N],r[N];
pair<double,double> ans[N];
pair<double,double> solve(ll m){
	double L[3],R[3];
	rep(i,0,3)L[i]=ld[i]+ld2[i];
	L[0]-=m;
	L[2]=L[2]*L[0]*2+L[1]*L[1];
	L[1]=L[1]*L[0]*2;
	L[0]=L[0]*L[0];
	rep(i,0,3){
		R[i]=0;
		rep(j,0,i+1)R[i]+=4*ld[j]*ld2[i-j];
	}
	return getrt(L[2]-R[2],L[1]-R[1],L[0]-R[0]);
}
double get(double xl,double yl,double xr,double yr){
	return sqrt((xl-xr)*(xl-xr)+(yl-yr)*(yl-yr));
}
int main(){
//	freopen("text.in","r",stdin);
	int n;
	scanf("%d%d",&xa,&ya);
	scanf("%d%d",&xb,&yb);
	scanf("%d",&n);
	rep(i,0,n){
		scanf("%d%d%d",&x[i],&y[i],&r[i]);
	}
	ll a=xb-xa,b=yb-ya;
	double x0=(xa+xb)/2.0,y0=(ya+yb)/2.0;
	ld[2]=a*a+b*b;
	ld[1]=0;
	ld[0]=(xa-x0)*(xa-x0)+(ya-y0)*(ya-y0);
	ld2[2]=ld[2];
	int cnt=0;
	rep(i,0,n){
		 ld2[1]=-2*b*(x[i]-x0)+2*a*(y[i]-y0);
		 ld2[0]=(x[i]-x0)*(x[i]-x0)+(y[i]-y0)*(y[i]-y0);
		 ans[cnt++]=solve(1ll*r[i]*r[i]);
	}
	sort(ans,ans+n);
	double res=1e18,R=-1e18;
	rep(i,0,n){
		//cout<<ans[i].fi<<' '<<ans[i].se<<"ans\n";
		if(ans[i].fi>R+fabs(R*eps)){
			if(ans[i].fi<-eps){
				res=-ans[i].fi;
			}
			else{
				if(R<-eps)res=0;
				else res=min(res,fabs(R));
			}
		}
		R=max(R,ans[i].se);
		/*if(i>38360){
			cout<<i<<' '<<res<<endl;
			cout<<ans[i].fi<<' '<<ans[i].se<<"ans\n";
			system("pause");
		}*/
	}
	if(R<-eps){
		res=0;
	}
	else res=min(res,fabs(R));
	//cout<<res<<"res\n";
	printf("%.10lf\n",get(xa,ya,x0+res*b,y0-res*a));
} 
/*
0 0 10 0
58
2 4 1
2 -4 1
8 6 1
8 -6 1
2 8 1
2 -8 1
8 10 1
8 -10 1
2 12 1
2 -12 1
8 14 1
8 -14 1
2 16 1
2 -16 1
8 18 1
8 -18 1
2 20 1
2 -20 1
8 22 1
8 -22 1
2 24 1
2 -24 1
8 26 1
8 -26 1
2 28 1
2 -28 1
8 30 1
8 -30 1
2 32 1
2 -32 1
8 34 1
8 -34 1
2 36 1
2 -36 1
8 38 1
8 -38 1
2 40 1
2 -40 1
8 42 1
8 -42 1
2 44 1
2 -44 1
8 46 1
8 -46 1
2 48 1
2 -48 1
8 50 1
8 -50 1
2 52 1
2 -52 1
8 54 1
8 -54 1
2 56 1
2 -56 1
8 58 1
8 -58 1
2 60 1
2 -60 1
*/