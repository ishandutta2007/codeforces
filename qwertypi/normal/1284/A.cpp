/* Hello, 2020! */

#include <bits/stdc++.h>

#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define vpii vector<pair<int, int>>
#define vppii vector<pair<pair<int, int>, pair<int, int>>>

using namespace std;
vector<string> A(100), B(100);
int32_t main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	} 
	for(int j = 0; j < m; j++){
		cin >> B[j];
	}
	int q;
	cin >> q;
	while(q--){
		int j;
		cin >> j;
		j--;
		cout << A[j % n] << B[j % m] << endl;;
	}
}