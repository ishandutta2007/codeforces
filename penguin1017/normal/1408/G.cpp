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
const int N=1600;
const int mod=998244353;
const ll Inf=1e18;
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
int A[N][N],a[N][N],sz[N],e[N],fa[N],temp[N];
int find(int x){
	if(fa[x]==x)return fa[x];
	return fa[x]=find(fa[x]);
} 
struct node{
	int i,j,k;
	node(int i=0,int j=0,int k=0):i(i),j(j),k(k){}
}p[N*N];
void merge(int u,int v){
	u=find(u),v=find(v);
	if(u==v){
		++e[u];
		if(sz[u]*(sz[u]-1)/2==e[u])A[u][1]++;
		return;
	}
	memset(temp,0,sizeof temp);
	rep(i,1,sz[u]+1){
		rep(j,1,sz[v]+1)temp[i+j]=add(temp[i+j],mul(A[u][i],A[v][j]));
	}
	copy(temp,temp+N,A[u]);
	sz[u]+=sz[v];
	e[u]+=e[v]+1;
	fa[v]=u;
	if(sz[u]*(sz[u]-1)/2==e[u])A[u][1]++;
}
int main(){
	//pre();
	int n;
	scanf("%d",&n);
	rep(i,1,n+1)rep(j,1,n+1)scanf("%d",&a[i][j]);
	int cnt=0;
	rep(i,1,n+1){
		rep(j,1,i)p[cnt++]=node(i,j,a[i][j]);
	}
	sort(p,p+cnt,[](node a,node b){return a.k<b.k;});
	rep(i,1,n+1)A[i][1]=1,sz[i]=1,fa[i]=i;
	rep(i,0,cnt){
		merge(p[i].i,p[i].j);
	}
	int u=find(1);
	rep(i,1,n+1)printf("%d ",A[u][i]);
}