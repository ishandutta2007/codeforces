#include <bits/stdc++.h>
#define IOS cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false);

using namespace std;

void sub(){
	int n, m;
	cin >> n >> m;
	int sum = 0;
	for(int i = 0; i < n; i++){
		int v;
		cin >> v;
		sum += v;
	}
	cout << min(sum, m) << endl;
}
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}