#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int f[30][30];
V<int> ans;
bool vis[30];
void dfs(int p){
	if(vis[p])RE;vis[p]=1;
	ans.PB(p);
	rep(i,0,26){
		if(f[i][p]){
			dfs(i);
		}
	}
}
void solve(){
	int n,l[30];string s;
	cin>>s;
	n=s.size();
	FILL(f,0);
	rep(i,1,n){
		f[s[i]-'a'][s[i-1]-'a']=1;
		f[s[i-1]-'a'][s[i]-'a']=1;
	}
	int t=0,lst;
	rep(i,0,26){
		lst=t;
		rep(j,0,26){
			t+=f[i][j];
		}
		if(t-lst>2){
			cout<<"NO\n";RE;
		}
		l[i]=t-lst;
	}
	if(t>50){
		cout<<"NO\n";RE;
	}
	ans.clear();
	FILL(vis,0);
	rep(i,0,26){
		if(l[i]<=1)dfs(i);
	}
	if(ans.size()!=26){
		cout<<"NO\n";RE;
	}
	cout<<"YES\n";
	for(auto u:ans)cout<<(char)(u+'a');
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}