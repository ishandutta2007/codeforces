#pragma GCC optimize("Ofast")
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
int n,a[205][205],len[205],ans[205],p[205];
set<int> s[205],t[205];
bool vis[205];
bool check(int start){
	FOR(i,1,n){
		ans[i]=0;t[i]=s[i];vis[i]=0;
		t[i].erase(start);
	}
	ans[1]=start;int now;vis[start]=1;
	FOR(i,2,n){
		now=0;
		rep(j,1,n){
			if(t[j].size()==1){
				if(now!=0){
					now=-1;break;
				}else now=(*t[j].begin());
			}
		} 
		if(now==-1)RE 0;
		if(!now){
			FOR(j,1,n){
				if(!vis[j]){
					now=j;break;
				}
			}
		}
		vis[now]=1;
		ans[i]=now;
		rep(j,1,n)t[j].erase(now);
	}
	FOR(i,1,n)p[ans[i]]=i;
	int maxi,mini;
	rep(i,1,n){
		maxi=0;mini=1e9;
		FOR(j,1,len[i]){
			gmax(maxi,p[a[i][j]]);
			gmin(mini,p[a[i][j]]);
		}
		if(maxi-mini>=len[i])RE 0;
	}
	FOR(i,1,n)cout<<ans[i]<<' ';
	cout<<'\n';
	RE 1;
}
void solve(){
	cin>>n;
	FOR(i,1,n)s[i].clear();
	rep(i,1,n){
		cin>>len[i];
		FOR(j,1,len[i])cin>>a[i][j],s[i].insert(a[i][j]);
	}
	FOR(i,1,n){
		if(check(i))break;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve(); 
	RE 0;
}