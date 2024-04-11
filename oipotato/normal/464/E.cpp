#include <bits/stdc++.h>
using namespace std;

//Start
typedef long long ll;
typedef double db;
#define mp(a,b) make_pair((a),(b))
#define x first
#define y second
#define be(a) (a).begin()
#define en(a) (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define R(i,a,b) for(int i=(a),I=(b);i<I;i++)
#define L(i,a,b) for(int i=(a),I=(b);i>I;i--)
const int iinf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;

//Bugs
/****
vector


int&k
****/

//Hash
const int mod=1e9+7;
const int N=1e5+100;
vector<int> b(N);
#define tran(x) (x>0?1:(x<0?-1:0))

//SegmentForest
struct SegmentForest{
	struct node{
		int ls,rs,val;
		node(){ls=0,rs=0,val=0;}
	};
	vector<node> t;int cnt;
	SegmentForest(){cnt=1;t.resize((int)1e7);}
	#define mid ((l+r)>>1)
	int newn(){return cnt++;}
	bool full(int k,int l,int r){
		return t[k].val==(b[r+1]-b[l]+mod)%mod;
	}
	int findz(int k,int x,int l=0,int r=N-1){ // leftest 0 on x's right
		if(r<x) return -1; 
		if(l>=x){
			if(full(k,l,r)) return -1; if(!t[k].val) return l;
			if(!full(t[k].ls,l,mid)) return findz(t[k].ls,x,l,mid);
			else return findz(t[k].rs,x,mid+1,r);
		}
		int res=-1;
		if(~(res=findz(t[k].ls,x,l,mid))) return res;
		else if(~(res=findz(t[k].rs,x,mid+1,r))) return res;
		return -1;
	}
	void revb(int p,int&k,int x,int l=0,int r=N-1){
		if(r<x||x<l) return;
		t[k=newn()]=t[p],(t[k].val+=b[x])%=mod;
		if(l==r) return;
		revb(t[p].ls,t[k].ls,x,l,mid);
		revb(t[p].rs,t[k].rs,x,mid+1,r);
	}
	void revs(int p,int&k,int x,int y,int l=0,int r=N-1){
		t[k=newn()]=t[p]; if(r<x||y<l||x>y) return;
		if(x<=l&&r<=y) return void(k=0);
		if(t[t[p].ls].val) revs(t[p].ls,t[k].ls,x,y,l,mid);
		if(t[t[p].rs].val) revs(t[p].rs,t[k].rs,x,y,mid+1,r);
		t[k].val=(t[t[k].ls].val+t[t[k].rs].val)%mod;
	}
	int add(int p,int x){
		int y=findz(p,x),k=0; 
		// cout<<"("<<p<<","<<x<<","<<y<<")\n";
		revs(p,k,x,y-1),p=k,revb(p,k,y);
		return k;
	}
	int rem(int p,int q,int l=0,int r=N-1){
		if(l==r) return tran(t[p].val-t[q].val);
		if(t[t[p].rs].val==t[t[q].rs].val) return rem(t[p].ls,t[q].ls,l,mid);
		else return rem(t[p].rs,t[q].rs,mid+1,r);
	}
	void print(int k,int l=0,int r=N-1){
		if(!k) return;
		print(t[k].ls,l,mid),print(t[k].rs,mid+1,r);
	}
}st;
using qnode=pair<int,int>;
struct cmp{bool operator()(qnode p,qnode q){return st.rem(p.x,q.x)>0;}};

//Graph
struct Graph{
	int n,ninf;
	vector<vector<int>> e;
	vector<int> to,val,pre,dis;
	vector<bool> vis;
	void assign(int _n){
		n=_n,e.resize(n),dis.assign(n,0);
		vis.assign(n,false),pre.assign(n,-1);
		ninf=st.add(0,N-1);
	}
	Graph(){} Graph(int _n){assign(_n);}
	void adde(int u,int v,int w){
		e[u].pb(sz(to)),to.pb(v),val.pb(w);
		e[v].pb(sz(to)),to.pb(u),val.pb(w);
	}	
	priority_queue<qnode,vector<qnode>,cmp> q;
	vector<int> path;
	void getpath(int u){
		if(!~u) return;
		getpath(pre[u]),path.pb(u);
	}
	void dijkstra(int s){
		R(i,0,n) dis[i]=ninf;
		dis[s]=0,q.push(mp(dis[s],s));
		while(sz(q)){
			int u=q.top().y; q.pop();
			// cout<<u<<'\n';
			if(vis[u]) continue; vis[u]=true;
			for(int v:e[u]){
				int tv=st.add(dis[u],val[v]);
				if(st.rem(tv,dis[to[v]])<0)
					dis[to[v]]=tv,pre[to[v]]=u,q.push(mp(dis[to[v]],to[v]));
			}
		}
	}
};

//Main
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	b[0]=1;R(i,1,N) b[i]=(b[i-1]<<1)%mod;
	int n,m; cin>>n>>m;
	Graph g(n);
	R(i,0,m){
		int u,v,w; cin>>u>>v>>w,--u,--v;
		g.adde(u,v,w);
	}
	int s,t; cin>>s>>t,--s,--t;
	g.dijkstra(s),g.getpath(t);
	if(g.dis[t]==g.ninf) cout<<-1<<'\n';
	else {
		cout<<st.t[g.dis[t]].val<<'\n'<<sz(g.path)<<'\n';
		for(int u:g.path) cout<<u+1<<" ";cout<<'\n';
	}
	return 0;
}