#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100005],b[100005];
int main(){
	ll n,m,k,x;
	cin>>n>>m>>k;
	for(ll i=1;i<=n;i++){
		cin>>x;
		a[x]=i;b[i]=x;
	}
	ll ans=0;
	for(ll i=1;i<=m;i++){
		cin>>x;
		ans=ans+(a[x]+k-1)/k;
		if(a[x]!=1){
			swap(b[a[x]-1],b[a[x]]);
			a[x]--;
			a[b[a[x]+1]]++;
		}
	}
	cout<<ans;
	return 0;
}