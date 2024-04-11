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
const int N=1e5+9;
const ll mod=998244353;
const ll Inf=1e18;
priority_queue<pii> PQ;
int b[N],cnt[N],q[N],ans[N],a[N];
vi g[N];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,x,y;
		scanf("%d%d%d",&n,&x,&y);
		rep(i,1,n+2)cnt[i]=0;
		rep(i,1,n+1)scanf("%d",&b[i]),cnt[b[i]]++;
		int p=0;
		while(!PQ.empty())PQ.pop();
		rep(i,1,n+2){
			g[i].clear();
			if(!cnt[i])p=i;
			else PQ.push({cnt[i],i});
		}
		int s=0;
		while(!PQ.empty()&&s!=x){
			auto u=PQ.top();
			PQ.pop();
			u.fi--;
			if(u.fi)PQ.push(u);
			a[s]=u.se;
			q[s++]=u.se; 
		}
		while(!PQ.empty()){
			auto u=PQ.top();
			if(u.fi<0)break;
			PQ.pop();
			u.fi=-u.fi;
			if(u.fi)PQ.push(u);
		}
		while(!PQ.empty()){
			auto u=PQ.top();
			PQ.pop();
			u.fi++;
			if(u.fi)PQ.push(u);
			a[s]=u.se;
			q[s++]=u.se; 
		}
		rep(i,y,n)q[i]=n+2;
		rep(i,0,x)g[a[i]].pb(q[i]);//cout<<a[i]<<' '<<q[i]<<"check\n";
		rep(i,x,n)a[i-x]=a[i],q[i-x]=q[i];
	/*	rep(i,0,n)cout<<a[i]<<' ';
		cout<<"A\n";
		rep(i,0,n)cout<<q[i]<<" ";
		cout<<"Q\n";*/
		sort(a,a+n-x);
		rep(i,1,n+2)cnt[i]=0;
		rep(i,0,n-x)cnt[q[i]]++;
		rep(i,0,n-x)if(cnt[a[i]])--cnt[a[i]],q[i]=a[i];
		else q[i]=n+2;
		int maxn=0;
		rep(i,1,n+2)cnt[i]=0;
		rep(i,0,n-x)cnt[a[i]]++;
		rep(i,1,n+2)maxn=max(maxn,cnt[i]);
		//cout<<maxn<<' '<<p<<' '<<n-x<<"?\n";
		int yes=1;
		rep(i,0,n-x){
			int u=a[i],v=q[(i-maxn+n-x)%(n-x)];
			g[u].pb(v);
			if(u==v)yes=0;
		}
		rep(i,1,n+1){
			int u=b[i];
			ans[i]=g[u][g[u].size()-1];
			g[u].pop_back();
		//	cout<<u<<' '<<ans[i]<<"ok\n";
			if(ans[i]==n+2)ans[i]=p;
		}
		if(!yes){
			printf("NO\n");
	/*	rep(i,1,n+1)printf("%d ",ans[i]);
		printf("\n");*/
			continue;
		}
		printf("YES\n");
		rep(i,1,n+1)printf("%d ",ans[i]);
		printf("\n");
	}
}