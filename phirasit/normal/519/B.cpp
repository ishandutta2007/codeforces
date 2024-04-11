#include <iostream>
#include <map>

using namespace std;

map<int, int> A, B;
int n;

int main() {
	cin >> n;
	for(int i = 0;i < n;i++) {
		int val;
		cin >> val;
		A[val]++;
		B[val]++;
	}
	for(int i = 0;i < n-1;i++) {
		int val; 
		cin >> val;
		A[val]--;
	}
	for(int i = 0;i < n-2;i++) {
		int val; 
		cin >> val;
		B[val]--;
	}
	int ans1, ans2;
	for(map<int, int>::iterator it = A.begin();it != A.end();it++) {
		if(it->second) {
			ans1 = it->first;
		}
	}
	B[ans1]--;
	for(map<int, int>::iterator it = B.begin();it != B.end();it++) {
		if(it->second) {
			ans2 = it->first;
		}
	}
	cout << ans1 << endl << ans2 << endl;
	return 0;
}