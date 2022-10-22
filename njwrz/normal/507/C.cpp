#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans;
void dfs(ll l,ll r,ll dr){
	if(l==r)return ;
	ans++;
	ll mid=(l+r)/2,t;
	if(mid>=n){
		t=1;dfs(l,mid,2);
	}else {
		t=2;dfs(mid+1,r,1);
	}
	if(dr!=t){
		ans+=(mid-l+1)*2-1;
	}
}
int main(){
	ll h;
	cin>>h>>n;
	ll l=1,r=1;
	for(ll i=0;i<h;i++)r*=2;
	dfs(l,r,1);
	cout<<ans;
	return 0;
}