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
const int N=4e5+9;
const ll mod=998244353;
const int Inf=1e9;
struct edge{
	int u,c,nxt;	
}e[2000000];
int vis[N],ans;
int head[N],s,t,ss,tt,cnt;
void add(int u,int v,int c){
	e[cnt]=(edge){v,c,head[u]},head[u]=cnt++;
	e[cnt]=(edge){u,0,head[v]},head[v]=cnt++;
}
bool bfs(int s,int t){
	memset(vis,-1,sizeof(vis));
	queue<int> q;
	q.push(s);
	vis[s]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];~i;i=e[i].nxt){
			int w=e[i].u;
			if(vis[w]==-1&&e[i].c>0){
				vis[w]=vis[u]+1;
				q.push(w);
			}
		}
	}
	return vis[t]!=-1;
}
int findf(int x,int t,int flow){
	if(x==t)return (ll)flow;
	int res=0;
	for(int i=head[x];~i;i=e[i].nxt){
		int w=e[i].u;
		if(vis[w]==vis[x]+1&&e[i].c>0){
			int ff=findf(w,t,min(e[i].c,flow));
			if(!ff)continue;
			e[i].c-=ff;e[i^1].c+=ff; 
			res+=ff;
			flow-=ff;
			if(!flow)break;
		}
	}
	if(!res)vis[x]=-1;
	return res;
}

void dinic(int s,int t){
	while(bfs(s,t))ans+=findf(s,t,Inf);
}
vi px,py;
int x[N],y[N],op[N],l[N],d[N],mini[N],sum[N],dd[N];
void addlim(int u,int v,int L,int R){
	if(L>R){
		puts("-1");
		exit(0);
	}
	dd[u]-=L;
	dd[v]+=L;
	add(u,v,R-L);
}
void solve(){
	add(tt,ss,Inf);
	int tot=0;
	rep(i,0,N){
		if(dd[i]>0){
			tot+=dd[i];
			add(s,i,dd[i]);
		}
		else if(dd[i]<0){
			add(i,t,-dd[i]);
		}
	}
	dinic(s,t);
	if(ans^tot){
		puts("-1");
		exit(0);
	}
	ans=0;
	dinic(ss,tt);
}
int main(){
	//pre();
	tt=N-1,ss=tt-1,t=ss-1,s=t-1;
	memset(head,-1,sizeof head);
	int n,m,r,b;
	scanf("%d%d",&n,&m);
	scanf("%d%d",&r,&b);
	int flag=0;
	if(r>b)swap(r,b),flag=1;
	rep(i,0,n)scanf("%d%d",&x[i],&y[i]),px.pb(x[i]),py.pb(y[i]);
	rep(i,0,m){
		scanf("%d%d%d",&op[i],&l[i],&d[i]);
		if(op[i]==1){
			px.pb(l[i]);
		}
		else{
			py.pb(l[i]);
		}
	}
	sort(all(px));
	sort(all(py));
	px.resize(unique(all(px))-px.begin());
	py.resize(unique(all(py))-py.begin());
	rep(i,0,n)x[i]=lower_bound(all(px),x[i])-px.begin(),sum[x[i]]++,y[i]=lower_bound(all(py),y[i])-py.begin(),sum[y[i]+px.size()]++;
	rep(i,0,m){
		if(op[i]==1){
			l[i]=lower_bound(all(px),l[i])-px.begin(); 
		}
		else{
			l[i]=lower_bound(all(py),l[i])-py.begin();
		}
	}
	rep(i,0,px.size()+py.size())mini[i]=sum[i];
	rep(i,0,m){
		if(op[i]==1){
			mini[l[i]]=min(mini[l[i]],d[i]);
		}
		else{
			mini[l[i]+px.size()]=min(mini[l[i]+px.size()],d[i]);
		//	cout<<l[i]+px.size()<<' '<<d[i]<<"upd\n";
		}
	}
	rep(i,0,n){
		add(x[i],y[i]+px.size(),1);
	}
	rep(i,0,px.size()){
		addlim(ss,i,sum[i]-mini[i]+1>>1,sum[i]+mini[i]>>1);
	}
	rep(i,px.size(),px.size()+py.size()){
		addlim(i,tt,sum[i]-mini[i]+1>>1,sum[i]+mini[i]>>1);
	}
	solve();
	printf("%lld\n",1ll*ans*r+1ll*(n-ans)*b);
	rep(i,0,n){
		if(e[i<<1].c^flag)printf("b");
		else printf("r");
	} 
}
/*
2 1
10 2
1 2
1 3
1 1 1

10 10
757507104 866538315
132477926 714514369
124560461 558537692
742608862 963508069
71928088 714514369
742608862 558537692
124560461 6748288
742608862 558537692
132477926 779426005
124560461 558537692
71928088 963508069
2 313078109 9
1 132477926 7
2 714514369 4
1 813163932 6
2 289876087 5
1 259870358 4
1 476187583 7
1 742608862 0
2 779426005 1
1 742608862 5
*/