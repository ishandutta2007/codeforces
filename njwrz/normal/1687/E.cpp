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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
#define sz(x) ((int)x.size())
using namespace std;
int n,a[100005];
V<P<int,int> > v[1000005];
int vis[100005];
int node[20],len;
V<P<int,V<int> > > ans;
V<int> fac[100005];
int need[1000005],f[1000005],h[1000005],is[100005];
int B=1e6;
void update(int i){
	FOR(j,2,B)h[j]=0;
	for(auto u:fac[i])h[u]=1;
	FOR(j,2,B)if(need[j]>0&&!h[j])need[j]--;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n){
		int x;
		cin>>x;a[i]=x;
		int t=x;
		for(int j=2;j*j<=x;j++)if(t%j==0){
			int cnt=0;
			while(t%j==0){
				cnt++;t/=j;
			}
			v[j].PB(MP(cnt,i));
			fac[i].PB(j);
		}
		if(t!=1){
			fac[i].PB(t);
			v[t].PB(MP(1,i));
		}
	}
	FOR(i,2,B)if((int)v[i].size()>=n-1){
		FOR(j,1,n)vis[j]=0;
		sort(ALL(v[i]));
		if((int)v[i].size()==n){
			node[++len]=v[i][0].S;node[++len]=v[i][1].S;
		}else{
			for(auto u:v[i])vis[u.S]=1;
			node[++len]=v[i][0].S;
			FOR(j,1,n)if(!vis[j])node[++len]=j;
		}
	}else if(!v[i].empty()){
		f[i]=1;
	}
	V<int> num;
	FOR(i,1,len)num.PB(node[i]);
	sort(ALL(num));num.erase(unique(ALL(num)),num.end());
	len=0;
	for(auto u:num)node[len++]=u;
	rep(i,0,len){
		for(auto u:fac[node[i]])if(f[u])need[u]=2;
	}
	rep(i,0,len){
		update(node[i]);
	}
	rep(i,0,len)is[node[i]]=1;
	FOR(i,2,B)if(need[i]>0){
		sort(ALL(v[i]));
		FOR(j,1,n)vis[j]=0;
		for(auto u:v[i])vis[u.S]=1;
		FOR(j,1,n)if(!vis[j]&&!is[j]){
			node[len++]=j;is[j]=1;
			update(j);
			if(need[i]<=0)break;
		}
	}
	sort(node,node+len);
	rep(mask,1,1<<len){
		int t=__builtin_popcount(mask);
		int now=2-t;
		if((t-1)&1)now=-now;
		V<int> hav;
		rep(i,0,len)if(mask&(1<<i))hav.PB(node[i]);
		if(now<0){
			FOR(j,1,-now){
				ans.PB(MP(1,hav));
			}
		}else{
			FOR(j,1,now){
				ans.PB(MP(0,hav));
			}
		}
	}
	cout<<ans.size()<<'\n';
	for(auto u:ans){
		cout<<u.F<<' '<<u.S.size()<<' ';
		for(auto tu:u.S)cout<<tu<<' ';
		cout<<'\n';
	}
	RE 0;
}