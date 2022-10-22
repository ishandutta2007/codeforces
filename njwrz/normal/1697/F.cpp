#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define int long long
#define lb long double
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
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
using namespace __gnu_pbds;
V<int> v[400005];
int dfn[400005],col[400005],in[400005],low[400005];
int cnt,cntcol;
int tn,n,m,k;
#define get(x,y) ((x-1)*k+y)
int len;
int sta[400005];
int ans[20005];
void dfs(int x){
	dfn[x]=low[x]=++cnt;in[x]=1;sta[++len]=x;
	for(auto u:v[x]){
		if(dfn[u]){
			if(in[u])gmin(low[x],dfn[u]);
		}else {
			dfs(u);
			gmin(low[x],low[u]);
		}
	}
	if(low[x]==dfn[x]){
		++cntcol;
		while(sta[len]!=x){
			col[sta[len]]=cntcol;
			in[sta[len]]=0;
			len--;
		}
		in[x]=0;col[x]=cntcol;len--;
	}
}
void solve(){
	cin>>n>>m>>k;
	tn=n*k;cnt=cntcol=0;
	FOR(i,1,tn*2)v[i].clear(),dfn[i]=col[i]=0;
	FOR(i,1,n){
		rep(j,1,k)v[get(i,j)+tn].PB(get(i,j+1)+tn);
		for(int j=k;j>=2;j--)v[get(i,j)].PB(get(i,j-1));
		if(i>1)FOR(j,1,k)v[get(i-1,j)].PB(get(i,j)),v[get(i,j)+tn].PB(get(i-1,j)+tn);
		v[get(i,k)].PB(get(i,k)+tn);
	}
	FOR(i,1,m){
		int tap;cin>>tap;
		if(tap==1){
			int x,y;
			cin>>x>>y;
			if(y==1){
				v[get(x,y)+tn].PB(get(x,y));
			}else {
				v[get(x,y)+tn].PB(get(x,y-1)+tn);
				v[get(x,y-1)].PB(get(x,y));
			}
		}else if(tap==2){
			int x,y,val;
			cin>>x>>y>>val;
			if(x>y)swap(x,y);
			FOR(j,1,k)FOR(j2,j,k){
				if(j+j2==val){
					if(j2>1)v[get(x,j)].PB(get(y,j2-1)+tn);
					else v[get(x,j)].PB(get(x,j)+tn);
					if(j>1)v[get(y,j2)].PB(get(x,j-1)+tn);
					else v[get(y,j2)].PB(get(y,j2)+tn);
				}
			}
		}else if(tap==3){
			int x,y,val;
			cin>>x>>y>>val;
			if(x>y)swap(x,y);
			FOR(j,1,k)FOR(j2,j,k){
				if(j+j2==val-1){
					v[get(x,j)+tn].PB(get(y,j2));
					v[get(y,j2)+tn].PB(get(x,j));
				}
			}
		}
	}
//	FOR(i,1,tn*2){
//		for(auto u:v[i]){
//			cout<<i<<' '<<u<<'\n';
//		}
//	}
//	cout<<'\n';
	FOR(i,1,2*tn)if(!dfn[i])dfs(i);
//	FOR(i,1,2*tn)cout<<col[i]<<' ';
//	cout<<'\n';
	FOR(i,1,tn){
		if(col[i]==col[i+tn]){
			cout<<-1<<'\n';RE;
		}
	}
	FOR(i,1,n)ans[i]=k+1;
	FOR(i,1,tn){
		if(col[i+tn]<col[i]){
//			cout<<"ok:"<<' '<<(i-1)/k+1<<' '<<(i-1)%k+1<<'\n';
			gmin(ans[(i-1)/k+1],(i-1)%k+1);
		}
	}
	FOR(i,1,n)cout<<ans[i]<<' ';
	cout<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}