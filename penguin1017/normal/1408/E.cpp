#include<bits/stdc++.h>
//#undef _GLIBCXX_HAVE_ICONV
//#include<bits/extc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&-(x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pr(x) {for(auto v:x)cout<<v<<' ';cout<<#x<<endl;}
using namespace std;
//using namespace __gnu_pbds;
const int N=1<<21;
const int mod=998244353;
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
ll quick(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int jie[N],inv[N];
void pre(){
	inv[0]=inv[1]=1,jie[0]=1;
	rep(i,2,N)inv[i]=-1ll*mod/i*inv[mod%i]%mod+mod;
	rep(i,1,N)inv[i]=mul(inv[i],inv[i-1]),jie[i]=mul(jie[i-1],i);
}
inline int C(int m,int n){
	if(n>m||m<0||n<0)return 0;
	return mul(mul(jie[m],inv[n]),inv[m-n]);
}
*/
struct node{
	int u,v,w;	
	node(int u=0,int v=0,int w=0):u(u),v(v),w(w){}
}p[N];
int a[N],b[N],cnt;
int fa[N];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int main(){
	//pre();
	int n,m;
	scanf("%d%d",&m,&n);
	rep(i,1,m+1)scanf("%d",&a[i]);
	rep(i,1,n+1)scanf("%d",&b[i]);
	ll sum=0;
	rep(i,1,m+1){
		int s;
		scanf("%d",&s);
		while(s--){
			int x;
			scanf("%d",&x);
			p[cnt++]=node(i+n,x,a[i]+b[x]);
			sum+=a[i]+b[x]; 
		}
	}
	sort(p,p+cnt,[](node a,node b){return a.w>b.w;});
	rep(i,1,n+m+1)fa[i]=i;
	rep(i,0,cnt){
		int u=find(p[i].u),v=find(p[i].v);
		if(u==v)continue;
		sum-=p[i].w;
		fa[u]=v;
	}
	printf("%lld\n",sum);
}