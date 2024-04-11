#include <bits/stdc++.h>
#define int long long
using namespace std;

// RE
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int u, v;
		cin >> u >> v;
		if(v == 1){
			cout << "NO" << endl;
		}else{
			cout << "YES" << endl;
			cout << u << ' ' << u * v << ' ' << u * v + u << endl;
		}
	}	
}