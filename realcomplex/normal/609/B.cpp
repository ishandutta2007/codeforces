#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll cnt[15];
ll ans = 0;
int main(){
	int n,m;
	cin >> n >> m;
	int k;
	for(int j = 0;j<n;j++){
		cin >> k;
		cnt[k]++;
	}
	for(int i = 0;i<15;i++){
		ans += cnt[i]*(n-cnt[i]);
	}
	cout << ans/2;
	return 0;
}