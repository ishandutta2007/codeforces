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
const int N=1<<21;
const ll mod=998244353;
const ll Inf=1e18;
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
	int x,y,op;
	point(int x=0,int y=0,int op=0):x(x),y(y),op(op){}
}p[N];
int pos[N],sum[N];
ll ans[N];
vi vec;
int main(){
	//pre();
	int n,k;
	scanf("%d%d",&n,&k);
	int cnt=0;
	rep(i,0,n){
		int x,y;
		scanf("%d%d",&x,&y);
		vec.pb(y);
		vec.pb(y-k);
		p[cnt++]=point(x-k,y,1);
		p[cnt++]=point(x,y,-1);
	}
	sort(all(vec));
	vec.resize(unique(all(vec))-vec.begin());
	sort(p,p+cnt,[](point &a,point &b){return a.x<b.x;});
	rep(i,0,cnt){
		int l=lower_bound(all(vec),p[i].y-k)-vec.begin();
		int r=lower_bound(all(vec),p[i].y)-vec.begin();
		rep(j,l+1,r+1){
			ans[sum[j]]+=1ll*(vec[j]-vec[j-1])*(p[i].x-pos[j]);
			sum[j]+=p[i].op;
			pos[j]=p[i].x;
		}
	}
	rep(i,1,n+1)printf("%lld ",ans[i]);
}