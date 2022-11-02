#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b)for(int i=(a),i##_end_=(b);i<i##_end_;++i)
#define PER(i,a,b)for(int i=(b)-1,i##_end_=(a);i>=i##_end_;--i)
#define pb push_back
#define fi first
#define se second
template<class T>inline bool umx(T& A,const T& B){return A<B?A=B,1:0;}
template<class T>inline bool umn(T& A,const T& B){return A>B?A=B,1:0;}
typedef long long LL;
typedef double db;
typedef pair<int,int> PII;
typedef pair<db,int> PDI;

const int maxn=200010;

// =============== Number Theory =============== 
void exgcd(LL a,LL b,LL&d,LL&x,LL&y){
	if(!b)d=a,x=1,y=0;
	else{exgcd(b,a%b,d,y,x);y-=x*(a/b);}
}
LL inv(LL a,LL M){
	LL d,x,y;exgcd(a,M,d,x,y);
	return d!=1 ? -1 : (x<0 ? x+M : x);
}

vector<int> a[maxn];
int f[maxn],v[maxn],p[maxn];
bool mark[maxn];
int n,m;

vector<int> ans;
void dfs(int n){
	if(n==0)return;
	for(auto&x:a[n])if(!mark[x])ans.pb(x);
	dfs(p[n]);
}

int main(){
//	freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	REP(i,0,m){
		int x=__gcd(i,m);
		a[x].pb(i);
		++v[x];
	}
	REP(i,0,n){
		int x;scanf("%d",&x);
		mark[x]=1;
		x=__gcd(x,m);
		--v[x];
	}
	REP(i,1,m+1)for(int j=i+i;j<=m;j+=i){
		if(umx(f[j],f[i]+v[i]))p[j]=i;
	}
	f[m]+=v[m];
//	REP(i,1,m+1)printf("%d %d\n",f[i],p[i]);putchar('\n');
	dfs(m);
	reverse(ans.begin(),ans.end());
//	for(auto&x:ans)printf("%d ",x);putchar('\n');
	
	printf("%d\n",f[m]);
	int now=1,lst=1;
	for(auto&x:ans){
		int g=__gcd(lst,m);
		now=(inv(lst/g,m/g)*(x/g))%m;
		lst=x;
		printf("%d ",now);
	}
	
	return 0;
}