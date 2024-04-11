#include <bits/stdc++.h>
#define int long long
using namespace std;
 
int32_t main(){
	int all = 0;
	int odd = 0;
	int n;
	int d = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		int v;
		cin >> v;
		all += v;
		odd += v / 2 + (v % 2 && i % 2 == 0);
	}
	cout << min(odd, all - odd);
}