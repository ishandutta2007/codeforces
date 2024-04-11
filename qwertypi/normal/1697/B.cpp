#include <bits/stdc++.h>
#define int long long
using namespace std;
 
int A[1000001];
int s[1000001];
int32_t main(){
	int n, q;
	cin >> n >> q;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	sort(A, A + n);
	for(int i = 0; i < n; i++) s[i + 1] = s[i] + A[i];
	for(int i = 0; i < q; i++){
		int x, y;
		cin >> x >> y;
		cout << s[n - x + y] - s[n - x] << endl;
	}
}