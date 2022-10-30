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
V<P<int,int>> v[100005]; 
int a[100005],ans[200005],cnt;
bool f[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	FOR(i,1,n)cin>>a[i];
	int x,y;
	FOR(i,1,m){
		cin>>x>>y;
		v[x].PB(MP(i,y));
		v[y].PB(MP(i,x));
		a[x]--;a[y]--;
	}
	queue<int> q;
//	FOR(i,1,n)cout<<a[i]<<' ';
//	cout<<'\n';
	FOR(i,1,n)if(a[i]>=0)q.emplace(i);
	while(!q.empty()){
		int cur=q.front();
		q.pop();
		for(auto u:v[cur]){
			if(f[u.F])continue;
			f[u.F]=1;
			ans[++cnt]=u.F;
			a[u.S]++;
			if(!a[u.S])q.emplace(u.S);
		}
	}
	if(cnt<m){
		cout<<"Dead";
	}else {
		cout<<"Alive\n";
		for(int i=cnt;i>=1;i--)cout<<ans[i]<<' ';
	}
	RE 0;
}