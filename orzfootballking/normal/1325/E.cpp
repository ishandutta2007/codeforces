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
V<int> v[1000005];
int f[1000005],step[1000005]; 
void dfs(int p){
	step[p]=1e9;f[p]=-1;
	for(auto u:v[p])if(step[u]<1e9)dfs(u);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,x,t,l;
	cin>>n;
	FOR(i,1,n){
		cin>>x;
		t=x;
		V<int> s;
		for(int j=2;j*j<=x;j++){
			if(t%j==0){
				l=0;
				while(t%j==0){
					t/=j;l++;
				}
				if(l&1)s.PB(j);
			}
		}
		if(t!=1)s.PB(t);
		if(!s.size()){
			cout<<1;RE 0;
		}
		if(s.size()==1){
			v[1].PB(s[0]);
			v[s[0]].PB(1);
		}else{
			v[s[0]].PB(s[1]);
			v[s[1]].PB(s[0]);
		}
	}
	FILL(f,-1);
	int cur,ans=1e9;
	bool ag;
	FOR(i,1,1000){
		queue<int> q;
		q.emplace(i);
		dfs(i);
		step[i]=0;
		while(!q.empty()){
			cur=q.front();q.pop();
			ag=1;
			for(auto u:v[cur]){
				if(step[u]==1e9){
					f[u]=cur;
					step[u]=step[cur]+1;
					q.emplace(u);
				}else{
					if(f[cur]==u&&ag)ag=0;
					else gmin(ans,step[cur]+step[u]+1);
				}
			}
		}
	}
	if(ans==1e9){
		cout<<-1;
	}else cout<<ans;
	RE 0;
}