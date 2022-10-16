#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=213456;
ll query(ll n, ll id){
	if(id&1) return (id+1)/2;
	if(n&1){
		if(id==2){
			return query(n/2, n/2)+(n+1)/2;
		}else{
			return query(n/2, (id-2)/2)+(n+1)/2;
		}
	}else{
		return query(n/2, id/2)+n/2;
	}
}
int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	ll n, q;
	cin>>n>>q;
	while(q--){
		ll x;
		cin>>x;
		cout<<query(n, x)<<endl;
	}
	return 0;
}