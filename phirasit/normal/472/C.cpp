#include <iostream>

#define N 100010

using namespace std;

string a[N], b[N];
int n, P[N];

int main() {
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i] >> b[i];
	}
	for(int i = 1;i <= n;i++) {
		cin >> P[i];	
	}
	string ls;
	bool first = true;
	for(int j = 1;j <= n;j++) {
		int i = P[j];
		string mn = (a[i] < b[i] ? a[i] : b[i]);
		string mx = (a[i] > b[i] ? a[i] : b[i]); 
		if(first) {
			ls = mn;
		}else if(ls < mn) {
			ls = mn;
		}else if(ls < mx) {
			ls = mx;
		}else {
			cout << "NO" << endl;
			return 0;
		}
		first = false;
	}
	cout << "YES" << endl;
	return 0;
}