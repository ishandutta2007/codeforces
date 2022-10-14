#include <bits/stdc++.h>
#define ll long long
#define db(x) cout << "=======>> " << #x << " is " << x << endl
#define pb push_back
#define fi first
#define se second
#define pii pair<ll,ll>
#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
ll p[1005];
ll n,m;
ll par(ll n) {
	if (p[n]==n){
		return n;
	}
	p[n]=par(p[n]);
	return p[n];
}

int main (){
	IOS;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		p[i]=i;
	}
	ll loc=1;
	vector<pii> tampung;
	while (m--){
		ll t,l,r;
		cin>> t>>l>>r;
		if (t==1){
			for (int i = l; i <r; i++){
				ll p1=par(i);
				ll p2=par(i+1);
				if (p1!=p2){
					p[p1]=p2;
				}
			}
		} else{
			tampung.pb({l,r});
		}	
	}
	for (int i = 0; i <tampung.size(); i++){
		ll cnt=0;
		map<ll,ll> mp;
		for (int j=tampung[i].fi; j<=tampung[i].se;j++){
			if(mp[par(j)]==0){
				cnt++;
				mp[par(j)]++;
			}
		}
		if (cnt==1){
			cout << "NO\n";
			return 0;
		}
		
	}
	cout << "YES\n";
	
	for (int i = 1; i <=n; i++){
		if(i>1) cout << " ";
		cout << 10000 - par(i);
	}
	cout << endl;
}