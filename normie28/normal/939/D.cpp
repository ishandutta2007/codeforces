#include<bits/stdc++.h>
using namespace std;
const long long N=100001;
vector<long long> adj[N];
vector<pair<long long,long long>> res;
long long x,vis[N],sz;
vector<long long> v;
 
void dfs(long long src){
	
	vis[src]=1;
	v.push_back(src);
	sz++;
	
	for(long long i=0;i<adj[src].size();i++)
	if(vis[adj[src][i]]==0)
	dfs(adj[src][i]);
}
 
int main(){
	ios_base::sync_with_stdio(false);
	long long i,j,k,x,y,ans=0; string s1,s2;
	cin>>k; cin>>s1>>s2;
	for(i=0;i<k;i++){x=s1[i]; y=s2[i]; adj[x].push_back(y); adj[y].push_back(x);}
 
	for(i=97;i<=122;i++){ 
	if(vis[i]==0){
	sz=0;
	v.clear();
	dfs(i); 
	for(j=0;j<v.size()-1;j++)
	res.push_back(make_pair(v[j],v[j+1]));
	ans=ans+sz-1;}}
 
	cout<<ans<<endl;
	for(i=0;i<ans;i++)
	cout<<(char)res[i].first<<" "<<(char)res[i].second<<endl;
 
	return 0;
}