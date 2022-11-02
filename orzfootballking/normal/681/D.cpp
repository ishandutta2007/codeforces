#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
V<int> v[100005],ans;
int a[100005],n; 
bool fa[100005];
void dfs(int p){
	for(int i=0;i<v[p].size();i++){
		if(a[v[p][i]]!=v[p][i]&&a[v[p][i]]!=a[p]){
			cout<<-1;exit(0);
		}
		dfs(v[p][i]);
	}
	if(a[p]==p)ans.PB(a[p]);
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int m,x,y;
	cin>>n>>m;
	FOR(i,1,m){
		cin>>x>>y;
		v[x].PB(y);
		fa[y]=1;
	}
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,n){
		if(!fa[i])dfs(i);
	}
	cout<<ans.size()<<'\n';
	for(int i=0;i<ans.size();i++)cout<<ans[i]<<'\n';
	RE 0;
}