#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main(){
	int ans = 0;
	int n;
	cin >> n;
	int curSum = 0;
	for(int i=0;i<n;i++){
		int a, b;
		cin >> a >> b;
		curSum += b - a;
		ans = max(ans, curSum);
	}
	cout << ans;
	return 0;
}