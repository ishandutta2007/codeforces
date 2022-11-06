#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
int n,m,X[200002],Y[200002],Z[200002],tot,ed[200002],Ans[200002],q,st[200002],num,ANS,P[1002],vis[200002],O[1002];
inline bool cmp(re int x,re int y){return Z[x]<Z[y];}
struct heap{
	priority_queue<int>q,d;
	inline void insert(re int x){q.push(x);}
	inline void del(re int x){d.push(x);}
	inline int first(){
		while(!d.empty()&&q.top()==d.top())q.pop(),d.pop();
		return q.top();
	}
	inline int calc(){
		if(q.size()-d.size()<3)return -1e18;
		re int x1=first();q.pop();
		re int x2=first();q.pop();
		re int x3=first();q.pop();
		re int ans=x1+x2+x3;
		q.push(x1),q.push(x2),q.push(x3);
		return ans;
	}
}H[200002],ans;
map<int,int>V[200002];
vector<int>G[800002];
inline void insert(re int p,re int l,re int r,re int x,re int y,re int z){
	if(l>=x&&r<=y){
		G[p].push_back(z);
		return;
	}
	re int mid=l+r>>1;
	if(x<=mid)insert(p<<1,l,mid,x,y,z);
	if(y>mid)insert(p<<1|1,mid+1,r,x,y,z);
}
inline int GET(re int x){
	re int s=0;
	for(re int i=1;i<=num;++i)s+=(X[P[i]]==x)||(Y[P[i]]==x);
	return s;
}
inline void solve(re int p,re int l,re int r){
	int Q[22];int n1=num,la=ANS;
	for(re int i=1;i<=n1;++i)Q[i]=P[i];
	random_shuffle(G[p].begin(),G[p].end());
	for(auto &z:G[p]){
		for(re int j=1;j<=num;++j)
			if(X[z]!=X[P[j]]&&X[z]!=Y[P[j]]&&Y[z]!=X[P[j]]&&Y[z]!=Y[P[j]]){
				ANS=min(ANS,Z[z]+Z[P[j]]);
			}
		P[++num]=z;
		for(re int i=num-1;i;--i)if(Z[P[i]]>Z[P[i+1]])swap(P[i],P[i+1]);
		for(re int i=1;i<=num;++i)O[i]=P[i];
		re int xx=num;num=0;
		for(re int i=1;i<=xx;++i)if((vis[X[O[i]]]<2&&vis[Y[O[i]]]<2))P[++num]=O[i],++vis[X[O[i]]],++vis[Y[O[i]]];
		for(re int i=1;i<=num;++i)--vis[X[P[i]]],--vis[Y[P[i]]];
		num=min(num,10ll);
	}
	if(l==r){
		Ans[l]=min(Ans[l],ANS);
	}
	else{
		re int mid=l+r>>1; 
		solve(p<<1,l,mid),solve(p<<1|1,mid+1,r);
	}
	ANS=la,num=n1;
	for(re int i=1;i<=num;++i)P[i]=Q[i];
}
signed main(){
	memset(ed,-1,sizeof(ed));
	n=read(),m=read(),ANS=1e18;
	for(re int i=1;i<=m;++i){
		X[i]=read(),Y[i]=read(),Z[i]=read();
		if(X[i]>Y[i])swap(X[i],Y[i]);
		V[X[i]][Y[i]]=i;
		H[X[i]].insert(-Z[i]),H[Y[i]].insert(-Z[i]);
	}
	for(re int i=1;i<=n;++i)ans.insert(H[i].calc());
	q=read();
	Ans[0]=-ans.first();
	for(re int i=1;i<=q;++i){
		re int o=read(),x=read(),y=read();
		if(x>y)swap(x,y);
		if(o==0){
			ans.del(H[x].calc()),ans.del(H[y].calc());
			H[x].del(-Z[V[x][y]]),H[y].del((-Z[V[x][y]]));
			ans.insert(H[x].calc()),ans.insert(H[y].calc());
			ed[V[x][y]]=i-1;
		}
		else{
			re int z=read();
			V[x][y]=++m,X[m]=x,Y[m]=y,Z[m]=z,st[m]=i;
			ans.del(H[x].calc()),ans.del(H[y].calc());
			H[x].insert(-Z[V[x][y]]),H[y].insert((-Z[V[x][y]]));
			ans.insert(H[x].calc()),ans.insert(H[y].calc());
		}
		Ans[i]=-ans.first();
	}
	for(re int i=1;i<=m;++i){
		if(ed[i]==-1)ed[i]=q;
		insert(1,0,q,st[i],ed[i],i);
	}
	solve(1,0,q);
	for(re int i=0;i<=q;++i)printf("%lld\n",Ans[i]);
}