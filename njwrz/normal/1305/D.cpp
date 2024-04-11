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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int n,l[1005],vis[1005],ch[1005]; 
V<int> v[1005],q,t;
void dfs(int p,int co){
	if(vis[p])RE;
	vis[p]=co;t.PB(p);
	for(auto u:v[p])dfs(u,co);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	int x,y;
	rep(i,1,n){
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	FOR(i,1,n)if(v[i].size()==1)q.PB(i);
	FOR(i,1,n)l[i]=v[i].size();
	int z,co;
	while(1){
		while(q.size()&&ch[q.back()])q.pop_back();
		x=q.back();q.pop_back();
		while(q.size()&&ch[q.back()])q.pop_back();
		if(!q.size()){
			cout<<"! "<<x;cout.flush();RE 0;
		}
		y=q.back();q.pop_back();
		cout<<"? "<<x<<' '<<y<<'\n';cout.flush();
		cin>>z;
		if(z==x){
			cout<<"! "<<x;cout.flush();RE 0;
		}else if(z==y){
			cout<<"! "<<y;cout.flush();RE 0;
		}else{
			FILL(vis,0);
			vis[z]=1;co=0;
			for(auto u:v[z]){
				t.clear();
				dfs(u,++co);
				if(vis[x]==co||vis[y]==co){
					l[z]--;
					for(auto iter:t)ch[iter]=1;
				}
			}
			if(l[z]==1)q.PB(z);
			if(!l[z]){
				cout<<"! "<<z;cout.flush();RE 0;
			}
		} 
	}
	RE 0;
}