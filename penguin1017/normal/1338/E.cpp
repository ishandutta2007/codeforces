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
#define de(x) cout<<#x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
#define pr(x) {for(auto v:x)cout<<x<<' ';cout<<#x<<endl;}
using namespace std;
const int N=8e3;
const ll mod=998244353;
const ll Inf=1e18;
bool e[N][N];
vi P,Q;
int deg[N];
bool vis[N];
bool cmp(int a,int b){
	return e[a][b];
}
int main(){
	int n;
	scanf("%d\n",&n);
	char c;
	rep(i,0,n){
		int j=0,p;
		while((c=getchar())!='\n'){
			if(c<='9')p=c-'0';
			else p=c-'A'+10;
			per(pos,0,4)e[i][pos+j]=p&1,p>>=1;
			j+=4;
		}
	}
/*	rep(i,0,n){
		rep(j,0,n)cout<<e[i][j];
		cout<<endl;
	}*/
	rep(i,0,n)rep(j,0,n)if(e[i][j])++deg[j];
	int last=n;
	ll ans=0;
	queue<int> q;
	rep(i,0,n){
		if(!deg[i])q.push(i);
	}
	while(!q.empty()){
		int u=q.front();
	//	cout<<u<<"check\n";
		q.pop();
		vis[u]=1;
		--last;
		ans+=(614ll*n+1)*last;
		rep(i,0,n){
			if(e[u][i]){
				--deg[i];
				if(!deg[i])q.push(i);
			}
		} 
	}
	int maxn=0;
	rep(i,0,n){
		if(deg[i]>deg[maxn])maxn=i;
	}
	if(!vis[maxn])P.pb(maxn),vis[maxn]=1;
	rep(i,0,n)if(!vis[i]&&e[i][maxn])vis[i]=1,P.pb(i);
	rep(i,0,n)if(!vis[i])Q.pb(i);
	sort(all(P),cmp);
	sort(all(Q),cmp);
/*	for(auto v:P)cout<<v<<' ';
	cout<<"P\n";
	for(auto v:Q)cout<<v<<' ';
	cout<<"Q\n";*/
	ll psz=P.size(),qsz=Q.size();
//	cout<<ans<<"ans1\n";
	ans+=3*psz*qsz;
	ans+=psz*(psz-1)/2+qsz*(qsz-1)/2;
	rep(i,0,n)deg[i]=0;
	for(auto u:P){
		for(auto v:Q){
			if(e[u][v])deg[v]++;
			else deg[u]++;
		}
	}
	rep(i,0,psz){
		int u=P[i];
	//	cout<<deg[u]<<' ';
		rep(j,i+1,psz){
			int v=P[j];
			if(deg[u]==deg[v])ans+=3;
			else ans+=2;
		}
	}
//	cout<<"deg\n";
	rep(i,0,qsz){
		int u=Q[i];
	//	cout<<deg[u]<<' ';
		rep(j,i+1,qsz){
			int v=Q[j];
			if(deg[u]==deg[v])ans+=3;
			else ans+=2;
		}
	}
//	cout<<"deg\n";
	printf("%lld\n",ans);
}