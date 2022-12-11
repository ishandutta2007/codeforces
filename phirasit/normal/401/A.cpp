#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<int,int> mp;
int n,x;

int main() {
	cin >> n >> x;
	int sum = 0;
	for(int i=0;i<n;i++) {
		int a;
		cin >> a;
		mp[a] = 1;
		sum += a;
	}
	if(sum < 0) sum = - sum;
	cout << sum/x + !!(sum%x) << endl;
	return 0;
}