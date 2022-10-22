#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
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
int p[200005],n,d;
int l[200005],r[200005],dp[200005];
priority_queue<P<int,int> ,V<P<int,int> > ,greater<P<int,int> > > q;
bool vis[200005];
set<int> s;
void erase(int x){
	vis[x]=1;
	r[l[x]]=r[x];
	l[r[x]]=l[x];
	s.erase(x);
}
void to(int x,int tl,int tr){
	int Tl=tl,Tr=tr;
	tl=lwb(p+1,p+n+1,tl)-p;tr=upb(p+1,p+n+1,tr)-p-1;
	gmin(tr,n);
	gmax(tl,1);
	int st=*s.lwb(tl);
	if(l[st]){
		st=l[st];
		int now=dp[x]+Tl-p[st];
		if(dp[st]>now){
			dp[st]=now;
			q.emplace(MP(now,st));
		}
		st=r[st];
	}
	while(st<=tr){
		dp[st]=dp[x];
		q.emplace(MP(dp[x],st));
		erase(st);
		st=r[st];
	}
	if(st<=n){
		int now=dp[x]+p[st]-Tr;
		if(dp[st]>now){
			dp[st]=now;
			q.emplace(MP(now,st));
		}
	}
} 
void tol(int x){
	int tl=p[x]-d-dp[x],tr=p[x]-d+dp[x];
	to(x,tl,tr);
}
void tor(int x){
	int tl=p[x]+d-dp[x],tr=p[x]+d+dp[x];
	to(x,tl,tr);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int Q,ST;
	cin>>n>>Q>>ST>>d;
	l[n+1]=n;r[0]=1;
	FOR(i,1,n){
		cin>>p[i];l[i]=i-1;r[i]=i+1;
		s.emplace(i);
	}
	s.emplace(n+1);
	FOR(i,1,n)dp[i]=1e9;
	q.emplace(MP(0,ST));
	dp[ST]=0;
	P<int,int> start=MP(ST,0);
	while(!q.empty()){
		P<int,int> cur=q.top();q.pop();
		if(dp[cur.S]!=cur.F)continue;
		swap(cur.F,cur.S);
		if(!vis[cur.F]){
			erase(cur.F);
		}
		if(cur.F>1&&cur!=start){
			int now=cur.S+p[cur.F]-p[cur.F-1];
			if(now<dp[cur.F-1]){
				dp[cur.F-1]=now;
				q.emplace(MP(now,cur.F-1));
			}
		}
		if(cur.F<n&&cur!=start){
			int now=cur.S+p[cur.F+1]-p[cur.F];
			if(now<dp[cur.F+1]){
				dp[cur.F+1]=now;
				q.emplace(MP(now,cur.F+1));
			}
		}
		tol(cur.F);
		tor(cur.F);
		if(cur==start)dp[ST]=1e9;
	}
	FOR(i,1,Q){
		int x,y;
		cin>>x>>y;
		if(y>=dp[x]||x==ST){
			cout<<"Yes\n";
		}else cout<<"No\n";
	}
	RE 0;
}