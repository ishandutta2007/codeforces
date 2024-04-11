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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
#define sz(x) ((int)x.size())
using namespace std;
const int mod=1e9+7;
V<int> v[200005];
int n;
bool line[200005];
P<int,int> to[200005];
int siz[200005];
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
void dfs(int x,int y){
	siz[x]=1;
	int cnt=0;
	for(auto u:v[x])if(u!=y){
		dfs(u,x);
		siz[x]+=siz[u];
		cnt++;
	}
	if(cnt==1){
		for(auto u:v[x])if(u!=y){
			to[x]=to[u];
			to[x].F++;
			line[x]=line[u];
		}
	}else if(!cnt){
		line[x]=1;
		to[x]=MP(0,x);
	}else{
		to[x]=MP(0,x);
		line[x]=0;
	}
}
int node[3];
int getnode(int x,int y){
	int now=x;
	FOR(_,1,y){
		for(auto u:v[now])if(siz[u]<siz[now]){
			now=u;break;
		}
	}
	RE now;
}
int dp[200005];
int get(int,int);
int get(int x){
	assert(x);
	if(dp[x]!=-1)RE dp[x];
	if(siz[x]&1)RE 0;
	if(line[x]){
		RE dp[x]=siz[x]/2;
	}
	int l1=to[x].F;int nod=to[x].S;
	int t1=0,t2=0;
	for(auto u:v[nod])if(siz[u]<siz[nod]){
		if(!t1)t1=u;else t2=u;
	}
	int re=0;
	rep(_,0,2){
		int l=0,r=0;
		for(auto u:v[t1])if(u!=nod){
			if(!l)l=u;else r=u;
		}
		rep(_2,0,2){
			int l2=0;
			if(r){
				if(!line[r]){
					swap(l,r);
					continue;
				}
				l2=siz[r];
			}
			if(l2>l1||(l1-l2)%2!=0){
				swap(l,r);continue;
			}
			add(re,get(t2,l));
			swap(l,r);
			if(l==r)break;
		}
		swap(t1,t2);
	}
	l1--;
	int l=t1,r=t2;
	rep(_,0,2){
		int l2=0;
		if(r){
			if(!line[r]){
				swap(l,r);
				continue;
			}
			l2=siz[r];
		}
		if(l2>l1||(l1-l2)%2!=0){
			swap(l,r);continue;
		}
		add(re,get(l));
		swap(l,r);
		if(l==r)break;
	}
	RE dp[x]=re;
}
int get(int x,int y){
	if((siz[x]+siz[y])&1)RE 0;
	if(!x||!y)RE get(x+y);
	if(!line[x]&&!line[y])RE 0;
	if(line[x]&&line[y]&&siz[x]==siz[y])RE 1;
	if(!line[x]||(line[y]&&siz[y]<siz[x]))swap(x,y);
	if(to[x].F>=to[y].F)RE 0;
	RE get(getnode(y,to[x].F+1));
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	FILL(dp,-1);
	cin>>n;
	if(n==1){
		cout<<2;RE 0;
	}
	rep(i,1,n*2){
		int x,y;
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	bool f=0;
	FOR(i,1,2*n){
		if(v[i].size()>2){
			f=1;
		}
		if(v[i].size()>3){
			cout<<0;RE 0;
		}
	}
	if(!f){
		cout<<(4*n+2*(n-2)*(n-1))%mod;RE 0;
	}
	int rt=-1;
	FOR(i,1,2*n){
		if(v[i].size()==3){
			rt=i;break;
		}
	}
	dfs(rt,-1);
	rep(i,0,3)node[i]=v[rt][i];
	int ans=0;
//	cout<<get(7)<<'\n';RE 0;
	rep(i,0,3){
		int tl=0,tr=0;
		rep(j,0,3)if(i!=j){
			if(!tl)tl=node[j];else tr=node[j];
		}
		int t1=0,t2=0;
		for(auto u:v[node[i]])if(u!=rt){
			if(!t1)t1=u;else t2=u;
		}
		if(v[node[i]].size()==1){
			add(ans,get(tl)*get(tr)%mod);
		}else if(v[node[i]].size()==2){
			add(ans,get(tl)*get(tr,t1)%mod);
			add(ans,get(tl,t1)*get(tr)%mod);
		}else {
			add(ans,get(tl,t2)*get(tr,t1)%mod);
			add(ans,get(tl,t1)*get(tr,t2)%mod);
		}
	}
	cout<<ans*4%mod;
	RE 0;
}