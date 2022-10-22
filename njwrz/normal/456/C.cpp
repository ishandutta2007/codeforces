#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll p[100005],n,a[100005],vis[100005];
ll f[100005];
ll dfs(ll id){
	if(id>n)return 0;
	if(f[id])return p[id];
	f[id]=1;ll t=id;
	if(a[id+1]==a[id]+1)id=id+1;
	return p[t]=a[t]*vis[t]
	+max(dfs(id+1),dfs(id+2));
}
int main(){
	ll q=0,t;
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		t=i;
		while(a[i+1]==a[t])i++;
		a[++q]=a[t];vis[q]=i-t+1;
	}
	n=q;
	cout<<max(dfs(1),dfs(2));
	return 0;
}