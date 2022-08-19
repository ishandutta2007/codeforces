#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct Edge{
	int x,y,z,st,ed;
	Edge(int xx=0,int yy=0,int zz=0,int ss=0,int ee=0):x(xx),y(yy),z(zz),st(ss),ed(ee){}
}e[1000005];

struct node{
	int p[35];
	void insert(int x){
		for(int i=30;i>=0;i--){
			if(x&(1<<i)){
				if(p[i]) x^=p[i];
				else return (void)(p[i]=x);
			}
		}
	}
	int ask(int x){
		for(int i=30;i>=0;i--) if(x&(1<<i)) x^=p[i];
		return x;
	}
}xj[30];

int n,m,top,te=1;
int bel[2000005],siz[2000005],dis[2000005];
vector<int> occ[6000000],s[2000005];
stack<pair<int,pii> > g[30];
pii q[2000005];
map<pii,int> bk;

void ins(int id,int l,int r,int ql,int qr,int c){
	if(ql>qr) return;
	if(l==ql&&r==qr){
		occ[id].push_back(c);
		return;
	}
	int mid=(l+r)/2;
	if(qr<=mid) ins(id<<1,l,mid,ql,qr,c);
	else if(ql>mid) ins(id<<1|1,mid+1,r,ql,qr,c);
	else ins(id<<1,l,mid,ql,mid,c),ins(id<<1|1,mid+1,r,mid+1,qr,c);
}

void merge(int x,int y,int z,int k){
	if(siz[bel[x]]>siz[bel[y]]) swap(x,y);
	siz[bel[y]]+=siz[bel[x]];
	int tmp=bel[x],lst=dis[x];
	for(int i=s[tmp].size()-1;i>=0;i--){
		int t=s[tmp][i];
		g[k].push(mp(t,mp(bel[t],dis[t])));
		s[bel[y]].push_back(t);
		bel[t]=bel[y],dis[t]^=lst^dis[y]^z;
	}
	s[tmp].clear();
}

void solve(int id,int l,int r){
	top++;
	for(int i=0;i<=30;i++) xj[top].p[i]=xj[top-1].p[i];
	for(auto t:occ[id]){
		if(bel[e[t].x]!=bel[e[t].y]) merge(e[t].x,e[t].y,e[t].z,top);
		else xj[top].insert(dis[e[t].x]^dis[e[t].y]^e[t].z);
	}
	if(l==r){
		printf("%d\n",xj[top].ask(dis[q[l].fi]^dis[q[l].se]));
		while(!g[top].empty()){
			int tx=g[top].top().fi,tmx=g[top].top().se.fi,tmy=g[top].top().se.se;
			s[tmx].push_back(s[bel[tx]][s[bel[tx]].size()-1]),s[bel[tx]].pop_back();
			siz[bel[tx]]--,bel[tx]=tmx,dis[tx]=tmy,siz[tmx]++;
			g[top].pop();
		}
		top--;
		return;
	}
	int mid=(l+r)/2;
	solve(id<<1,l,mid); solve(id<<1|1,mid+1,r);
	while(!g[top].empty()){
		int tx=g[top].top().fi,tmx=g[top].top().se.fi,tmy=g[top].top().se.se;
		s[tmx].push_back(s[bel[tx]][s[bel[tx]].size()-1]),s[bel[tx]].pop_back();
		siz[bel[tx]]--,bel[tx]=tmx,dis[tx]=tmy,siz[tmx]++;
		g[top].pop();
	}
	top--;
	return;
}

int main(){
	n=readint(); m=readint();
	int opt,x,y,z;
	for(int i=1;i<=m;i++){
		x=readint(); y=readint(); z=readint();
		e[i]=Edge(x,y,z,1,-1),bk[mp(x,y)]=bk[mp(y,x)]=i;
	}
	int Q=readint();
	while(Q--){
		opt=readint(); x=readint(); y=readint();
		if(opt==1) e[++m]=Edge(x,y,readint(),te,-1),bk[mp(x,y)]=bk[mp(y,x)]=m;
		else if(opt==2) e[bk[mp(x,y)]].ed=te-1;
		else q[te++]=mp(x,y);
	}
	for(int i=1;i<=m;i++) if(e[i].ed<0) e[i].ed=te;
	for(int i=1;i<=m;i++) ins(1,1,te-1,e[i].st,min(te-1,e[i].ed),i);
	for(int i=1;i<=n;i++) bel[i]=i,siz[i]=1,s[i].push_back(i);
	if(te>1) solve(1,1,te-1);
	return 0;
}