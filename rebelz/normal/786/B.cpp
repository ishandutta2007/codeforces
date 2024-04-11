#include<bits/stdc++.h>

#define pii pair<ll,ll>
#define mp make_pair

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=270000;
priority_queue<pii,vector<pii>,greater<pii> > q;
int n,m,s,tot;
int v[5000005],nxt[5000005],h[600005];
ll c[5000005],dis[600005];
bool vis[600005];

void addedge(int x,int y,ll z){v[++tot]=y; c[tot]=z; nxt[tot]=h[x]; h[x]=tot;}

void build(int id,int l,int r){
	addedge(id+MAXN,id,0);
	if(l==r) return addedge(id,id+MAXN,0);
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	addedge(id<<1,id,0);
	addedge(id<<1|1,id,0);
	addedge(id+MAXN,(id<<1)+MAXN,0);
	addedge(id+MAXN,(id<<1|1)+MAXN,0);
}

int find(int id,int l,int r,int ss){
	if(l==r) return id;
	int mid=(l+r)/2;
	if(ss<=mid) return find(id<<1,l,mid,ss);
	else return find(id<<1|1,mid+1,r,ss);
}

void work1(int id,int l,int r,int ql,int qr,int k,int z){
	if(l==ql&&r==qr) return addedge(k,id+MAXN,z);
	int mid=(l+r)/2;
	if(qr<=mid) work1(id<<1,l,mid,ql,qr,k,z);
	else if(ql>mid) work1(id<<1|1,mid+1,r,ql,qr,k,z);
	else work1(id<<1,l,mid,ql,mid,k,z),work1(id<<1|1,mid+1,r,mid+1,qr,k,z);
}

void work2(int id,int l,int r,int ql,int qr,int k,int z){
	if(l==ql&&r==qr) return addedge(id,k+MAXN,z);
	int mid=(l+r)/2;
	if(qr<=mid) work2(id<<1,l,mid,ql,qr,k,z);
	else if(ql>mid) work2(id<<1|1,mid+1,r,ql,qr,k,z);
	else work2(id<<1,l,mid,ql,mid,k,z),work2(id<<1|1,mid+1,r,mid+1,qr,k,z);
}

void dij(int s){
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	q.push(mp(0,s));
	while(!q.empty()){
		int u=q.top().second; q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(int p=h[u];p;p=nxt[p]){
			if(dis[v[p]]>dis[u]+c[p]){
				dis[v[p]]=dis[u]+c[p];
				q.push(mp(dis[v[p]],v[p]));
			}
		}
	}
}

int main(){
	n=readint(); m=readint(); s=readint();
	build(1,1,n);
	s=find(1,1,n,s)+MAXN;
	int opt,x,y,z;
	while(m--){
		opt=readint(); x=readint(); y=readint(); z=readint();
		if(opt==1) addedge(find(1,1,n,x),find(1,1,n,y)+MAXN,z);
		else if(opt==2) work1(1,1,n,y,z,find(1,1,n,x),readint());
		else if(opt==3) work2(1,1,n,y,z,find(1,1,n,x),readint());
	}
	dij(s);
	for(int i=1;i<=n;i++){
		ll tmp=dis[find(1,1,n,i)];
		if(tmp==dis[0]) printf("-1 ");
		else printf("%lld ",dis[find(1,1,n,i)+MAXN]);
	}
	printf("\n");
	return 0;
}