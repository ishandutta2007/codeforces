#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll unsigned long long
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
V<int> v[300005];
int n,ans[300005],num[300005];
struct LCA{
	int to[300005][19],d[300005];
	int lca(int x,int y){
		if(d[x]<d[y])swap(x,y);
		int t=d[x]-d[y];
		rep(i,0,19){
			if(t&(1<<i))x=to[x][i];
		} 
		if(x==y)RE x;
		for(int i=18;i>=0;i--){
			if(to[x][i]!=to[y][i]){
				x=to[x][i];
				y=to[y][i];
			}
		}
		RE to[x][0];
	}
	int getdis(int x,int y){
		int dis=0;
		if(d[x]<d[y])swap(x,y);
		int t=d[x]-d[y];
		rep(i,0,19){
			if(t&(1<<i))x=to[x][i],dis+=(1<<i);
		} 
		if(x==y)RE dis;
		for(int i=18;i>=0;i--){
			if(to[x][i]!=to[y][i]){
				x=to[x][i];dis+=(1<<(i+1));
				y=to[y][i];
			}
		}
		dis+=2;
		RE dis;
	}
	void dfs(int x){
		for(auto u:v[x])if(u!=to[x][0]){
			to[u][0]=x;d[u]=d[x]+1;
			dfs(u);
		}
	}
	int get(int x,int y){
		rep(i,0,19){
			if(y&(1<<i)){
				x=to[x][i];
			}
		}
		RE x;
	}
	void init(){
		dfs(1);
		rep(i,1,19){
			FOR(j,1,n){
				to[j][i]=to[to[j][i-1]][i-1];
			}
		}
	}
}LCA;
int a[300005];
ll pow_7[300005],val[10000000];
int ch[10000000][2],cntnode,cnt,root[300005];
struct query{
	int from,lca,L,R,it;
};
V<query> qu[300005];
void build(int &x,int l,int r){
	x=++cntnode;
	if(l==r)RE;
	int mid=(l+r)>>1;
	build(ch[x][0],l,mid);
	build(ch[x][1],mid+1,r);
}
int update(int lst,int &x,int l,int r,int iter){
	if(!x)x=++cntnode;
	val[x]=val[lst];
	ch[x][0]=ch[lst][0];
	ch[x][1]=ch[lst][1];
	if(l==r){
		val[x]^=1;RE val[x];
	}
	int mid=(l+r)>>1;
	if(mid>=iter){
		ch[x][0]=0;
		int t=update(ch[lst][0],ch[x][0],l,mid,iter);
		if(t){
			val[x]+=pow_7[iter-l];
		}else val[x]-=pow_7[iter-l];
		RE t;
	}else{
		ch[x][1]=0;
		int t=update(ch[lst][1],ch[x][1],mid+1,r,iter);
		if(t){
			val[x]+=pow_7[iter-l];
		}else val[x]-=pow_7[iter-l];
		RE t; 
	}
}
void dfs(int x,int fa){
	num[x]=++cnt;
	update(root[fa],root[x],1,n,a[x]);
	for(auto u:v[x])if(u!=fa){
		dfs(u,x);
	}
}
int find(int x1,int x2,int l,int r){
	if(l==r)RE l;
	int mid=(l+r)>>1;
	if(val[ch[x1][0]]!=val[ch[x2][0]])RE find(ch[x1][0],ch[x2][0],l,mid);
	else RE find(ch[x1][1],ch[x2][1],mid+1,r);
}
int find(int x1,int x2,int tl,int tr,int l,int r){
	if(l>tr||tl>r)RE -1;
	if(l>=tl&&r<=tr){
//		cout<<tl<<"    "<<tr<<' '<<val[x1]<<' '<<val[x2]<<'\n';
		if(val[x1]==val[x2]){
			RE -1;
		}else RE find(x1,x2,l,r);
	}
	int mid=(l+r)>>1;
	int t=find(ch[x1][0],ch[x2][0],tl,tr,l,mid);
	if(t!=-1)RE t;
	RE find(ch[x1][1],ch[x2][1],tl,tr,mid+1,r);
}
void dfs2(int x,int fa){
	for(auto u:v[x])if(u!=fa){
		dfs2(u,x);
	}
	for(auto u:qu[x]){
		ans[u.it]=-1;
		if(a[u.lca]>=u.L&&a[u.lca]<=u.R){
			int l2=a[u.lca]-1,r2=a[u.lca]+1;
			if(l2>=u.L){
				gmax(ans[u.it],find(root[u.from],root[x],u.L,l2,1,n));
			}
			if(find(root[u.from],root[x],l2+1,l2+1,1,n)==-1)ans[u.it]=l2+1;
			if(u.R>=r2){
				gmax(ans[u.it],find(root[u.from],root[x],r2,u.R,1,n));
			}
		}else ans[u.it]=find(root[u.from],root[x],u.L,u.R,1,n);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin>>n>>q;
	pow_7[0]=1;
	FOR(i,1,n)cin>>a[i],pow_7[i]=pow_7[i-1]*7;
	rep(i,1,n){
		int x,y;
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	} 
	LCA.init();
	build(root[0],1,n);
	dfs(1,0);
	FOR(i,1,q){
		int from,to,L,R;
		cin>>from>>to>>L>>R;
		if(num[from]>num[to]){
			swap(from,to);
		}
		int t=LCA.lca(from,to);
		qu[to].PB((query){
			from,t,L,R,i
		});
	}
	dfs2(1,0);
	FOR(i,1,q)cout<<ans[i]<<'\n';
	RE 0;
}