#include <iostream>

using namespace std;
int main(){
	int ans = 0;
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int a, b, c;
		cin >> a >> b >> c;
		ans += (a + b + c) >= 2;
	}
	cout << ans;
}