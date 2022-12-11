#include <iostream>

#define PRINT(x) cout << "PRINT " << x << endl
#define LF cout << "LEFT" << endl
#define RG cout << "RIGHT" << endl

using namespace std;

int n, k;
string str;

int main() {
	cin >> n >> k >> str;
	k--;
	if(k <= (n-k-1)) {
		for(int i = k;i >= 0;i--) {
			PRINT(str[i]);
			if(i > 0) {
				LF;
			}
		}
		for(int i = 0;i <= k;i++) {
			if(i+1 < n) {
				RG;
			}
		}
		for(int i = k+1;i < n;i++) {
			PRINT(str[i]);
			if(i+1 < n) {
				RG;
			}
		}
	}else {
		for(int i = k;i < n;i++) {
			PRINT(str[i]);
			if(i+1 < n) {
				RG;
			}
		}
		for(int i = k;i < n;i++) {
			LF;
		}
		for(int i = k-1;i >= 0;i--) {
			PRINT(str[i]);
			if(i > 0) {
				LF;
			}
		}
	}
	return 0;
}