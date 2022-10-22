#pragma GCC optimize("Ofast")
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
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
struct edge{
	int u,v,g,s;
};
edge p[50005];
int n,m,fa[205];
int use[205],len,used[205];
bool cmp2(int x,int y){
	RE p[x].s<p[y].s;
}
int getfa(int x){
	RE fa[x]==x?x:(fa[x]=getfa(fa[x]));
}
void merge(int x,int y){
	x=getfa(x);y=getfa(y);
	if(x!=y){
		fa[x]=y;
	}
} 
int check(){
	FOR(i,1,n)fa[i]=i;
	FOR(i,1,len)used[i]=0;
	int cnt=1;
	FOR(i,1,len){
		int nu=use[i];
		edge u=p[nu];
		if(getfa(u.u)!=getfa(u.v)){
			merge(u.u,u.v);
			used[i]=1;
			if(++cnt==n){
				len=0;
				FOR(j,1,i){
					if(used[j])use[++len]=use[j];
				}
				RE u.s; 
			}
		}
	}
	int t=len;
	len=0;
	FOR(j,1,t){
		if(used[j])use[++len]=use[j];
	}
	RE -1;
}
bool cmp1(edge x,edge y){
	RE x.g<y.g;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int g,s;
	cin>>n>>m>>g>>s;
	FOR(i,1,m){
		cin>>p[i].u>>p[i].v>>p[i].g>>p[i].s;
	}
	sort(p+1,p+m+1,cmp1);
	int ans=2e18;
	FOR(i,1,m){
		use[++len]=i;
		for(int j=len-1;j>=0;j--){
			if(p[use[j]].s<p[use[len]].s){
				for(int k=len;k>j+1;k--)use[k]=use[k-1];
				use[j+1]=i;
				break;
			}
		}
		int t=check();
		if(t==-1)continue;
		gmin(ans,p[i].g*g+t*s);
	}
	if(ans==2e18){
		cout<<-1;
	}else cout<<ans;
	RE 0;
}