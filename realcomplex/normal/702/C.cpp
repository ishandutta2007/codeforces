#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll ans = 0;

int main(){
	int n,m;
	cin >> n >> m;
	ll cit[n];
	ll tow[m+1];
	tow[0] = 1000000000000;
	for(int j = 0;j<n;j++)cin >> cit[j];
	for(int j = 1;j<=m;j++)cin >> tow[j];
	int l = 1;
	for(int j = 0;j<n;j++){
		while(tow[l]<=cit[j]&&l<m)l++;
		ans = max(ans,ll(min(ll(abs(tow[l]-cit[j])),ll(abs(tow[l-1]-cit[j])))));
	}
	cout << ans << "\n";
	return 0;
}