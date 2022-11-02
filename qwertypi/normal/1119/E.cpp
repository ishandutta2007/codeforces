#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int single = 0;
	int n;
	cin >> n;
	long long ans = 0; 
	for(int i=0;i<n;i++){
		int val;
		cin >> val;
		// Case 1
		int cnt = min(val / 2, single);
		val -= 2 * cnt;
		single -= cnt;
		ans += cnt;
		// Case 2
		ans += val / 3;
		single += val % 3;
	}
	cout << ans;
}