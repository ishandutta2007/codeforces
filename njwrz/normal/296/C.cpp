#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100005],f[100005],l[100005],r[100005],d[100005];
int main(){
	ll n,m,k;
	cin>>n>>m>>k;
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(ll i=1;i<=m;i++){
		cin>>l[i]>>r[i]>>d[i];
	}
	ll l1,r1;
	for(ll i=0;i<k;i++){
		cin>>l1>>r1;
		f[l1]++;f[r1+1]--;
	}
	ll t=0;
	for(ll i=1;i<=m;i++){
		t+=f[i];
		d[i]*=t;
	}
	memset(f,0,sizeof(f));
	for(ll i=1;i<=m;i++){
		f[l[i]]+=d[i];f[r[i]+1]-=d[i];
	}
	t=0;
	for(ll i=1;i<=n;i++){
		t+=f[i];
		cout<<a[i]+t<<' ';
	}
	return 0;
}