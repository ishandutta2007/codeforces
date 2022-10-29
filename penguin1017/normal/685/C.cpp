#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&-(x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<#x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
#define pr(x) {for(auto v:x)cout<<v<<' ';cout<<#x<<endl;}
using namespace std;
const int N=1e5;
const ll mod=998244353;
const ll Inf=7e18;
const ll inf=3e18;
/*
inline int add(int a,const int &b){
	a+=b;
	if(a>=mod)a-=mod;
	return a;
}
inline int sub(int a,const int &b){
	a-=b;
	if(a<0)a+=mod;
	return a;
}
inline int mul(const int &a,const int &b){return 1ll*a*b%mod;}
int jie[N],inv[N];
ll quick(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
inline int C(int m,int n){
	if(n>m||m<0||n<0)return 0;
	return mul(mul(jie[m],inv[n]),inv[m-n]);
}
void pre(){
	inv[0]=inv[1]=1,jie[0]=1;
	rep(i,2,N)inv[i]=-1ll*mod/i*inv[mod%i]%mod+mod;
	rep(i,1,N)inv[i]=mul(inv[i],inv[i-1]),jie[i]=mul(jie[i-1],i);
}
*/
struct point{
	ll a,b,c,d;
	point(ll a=0,ll b=0,ll c=0,ll d=0):a(a),b(b),c(c),d(d){}
	build(ll x,ll y,ll z){
		a=x+y+z,b=x+y-z,c=x-y+z,d=-x+y+z;
	}
	void put(){
		cout<<a<<'\t'<<b<<'\t'<<c<<'\t'<<d<<endl;
	}
}p[N];
int n;

ll x[N],y[N],z[N],X,Y,Z;
int T;
bool cal(ll D){
//	cout<<D<<"check\n";
/*	if((D==1433032200290071796||D==1433032200290071795)&&T==50000){
		cout<<1<<endl;
		cout<<n<<endl;
		rep(i,0,n)cout<<x[i]<<' '<<y[i]<<' '<<z[i]<<endl;
	}*/
	ll a=Inf,a_=-Inf,b=Inf,b_=-Inf,c=Inf,c_=-Inf,d=Inf,d_=-Inf;
	rep(i,0,n){
		a=min(a,p[i].a+D);
		a_=max(a_,p[i].a-D);
		b=min(b,p[i].b+D);
		b_=max(b_,p[i].b-D);
		c=min(c,p[i].c+D);
		c_=max(c_,p[i].c-D);
		d=min(d,p[i].d+D);
		d_=max(d_,p[i].d-D);
	}
//	cout<<a<<' '<<a_<<"A\n"<<b<<' '<<b_<<"B\n"<<c<<' '<<c_<<"C\n"<<d<<' '<<d_<<"D\n";
	ll A=a,B=b,C=c,DD=d; 
	int ok=0;
	if(A%2){
		if(A>a_)--A;
		else ok=1; 
	}
	if(B%2){
		if(B>b_)--B;
		else ok=1; 
	}
	if(C%2){
		if(C>c_)--C;
		else ok=1; 
	}
	if(DD%2){
		if(DD>d_)--DD;
		else ok=1; 
	}
	if(!ok){
		if(B+C+DD>A){
			ll k=B+C+DD-A,k2=B-b_;
			k2-=k2&1;
			if(k2>k)B-=k;
			else B-=k2;
		} 
		if(B+C+DD>A){
			ll k=B+C+DD-A,k2=C-c_;
			k2-=k2&1;
			if(k2>k)C-=k;
			else C-=k2;
		} 
		if(B+C+DD>A){
			ll k=B+C+DD-A,k2=DD-d_;
			k2-=k2&1;
			if(k2>k)DD-=k;
			else DD-=k2;
		} 
		if(B+C+DD<A){
			ll k=A-B-C-DD,k2=A-a_;
			k2-=k2&1;
			if(k2>k)A-=k;
			else A-=k2;
		} 
		if(A!=B+C+DD)ok=1;
	}
	if(!ok){
		X=(B+C)/2,Z=(C+DD)/2,Y=(B+DD)/2;
		return 1;
	}
	ok=0;
	A=a,B=b,C=c,DD=d; 
	if(A%2==0){
		if(A>a_)--A;
		else ok=1; 
	}
	if(B%2==0){
		if(B>b_)--B;
		else ok=1;
	}
	if(C%2==0){
		if(C>c_)--C;
		else ok=1;
	}
	if(DD%2==0){
		if(DD>d_)--DD;
		else ok=1;
	}
	if(!ok){
		if(B+C+DD>A){
			ll k=B+C+DD-A,k2=B-b_;
			k2-=k2&1;
			if(k2>k)B-=k;
			else B-=k2;
		} 
		if(B+C+DD>A){
			ll k=B+C+DD-A,k2=C-c_;
			k2-=k2&1;
			if(k2>k)C-=k;
			else C-=k2;
		} 
		if(B+C+DD>A){
			ll k=B+C+DD-A,k2=DD-d_;
			k2-=k2&1;
			if(k2>k)DD-=k;
			else DD-=k2;
		} 
		if(B+C+DD<A){
			ll k=A-B-C-DD,k2=A-a_;
			k2-=k2&1;
			if(k2>k)A-=k;
			else A-=k2;
		} 
		if(A!=B+C+DD)ok=1;
	}
	if(ok)return 0;
	X=(B+C)/2,Z=(C+DD)/2,Y=(B+DD)/2;
	return 1;
}
bool check(ll d){
	ll mini,maxn;
	mini=Inf,maxn=-Inf;
	rep(i,0,n){
		mini=min(mini,p[i].a+d);
		maxn=max(maxn,p[i].a-d);
	}
	if(mini<maxn)return 0;
	mini=Inf,maxn=-Inf;
	rep(i,0,n){
		mini=min(mini,p[i].b+d);
		maxn=max(maxn,p[i].b-d);
	}
	if(mini<maxn)return 0;
	mini=Inf,maxn=-Inf;
	rep(i,0,n){
		mini=min(mini,p[i].c+d);
		maxn=max(maxn,p[i].c-d);
	}
	if(mini<maxn)return 0;
	mini=Inf,maxn=-Inf;
	rep(i,0,n){
		mini=min(mini,p[i].d+d);
		maxn=max(maxn,p[i].d-d);
	}
	if(mini<maxn)return 0;
	return cal(d);
}
void doit(){
	scanf("%d",&n);
	rep(i,0,n){
		scanf("%lld%lld%lld",&x[i],&y[i],&z[i]);
		p[i].build(x[i],y[i],z[i]);
	//	p[i].put();
	//	cout<<(p[i].a-p[i].d>>1)<<' '<<(p[i].a-p[i].c>>1)<<' '<<(p[i].a-p[i].b>>1)<<"inv\n";
	}
	ll l=0,r=inf+50;
	while(l<r){
		ll m=l+r>>1;
		if(check(m))r=m;
		else l=m+1;	
	}
	cal(l);
	printf("%lld %lld %lld\n",X,Y,Z);
}
int main(){
	//pre();
	scanf("%d",&T);
	rep(Tcase,1,T+1)doit(); 
}