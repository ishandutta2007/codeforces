#pragma GCC optimize("Ofast,unroll-loops")
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
V<int> v[205];int n;
string s;
int ans[205];
void dfs(int p,int co){
	if(ans[p]){
		if(co!=ans[p]){
			cout<<"NO";exit(0);
		}
		RE;
	}
	ans[p]=co;
	for(int i=0;i<v[p].size();i++){
		dfs(v[p][i],3-co);
	}
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	cin>>n>>s;
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(s[j]>s[i]){
				v[i].PB(j);v[j].PB(i);
			}
		}
	}
	for(int i=0;i<n;i++){
		if(!ans[i]){
			dfs(i,1);
		}
	}
	cout<<"YES\n";
	for(int i=0;i<n;i++)cout<<ans[i]-1;
	RE 0;
}