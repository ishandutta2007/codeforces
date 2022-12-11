#include <iostream>

#define N 200010

using namespace std;

string str;
int rem[N];
int m;

int main() {
	cin >> str >> m;
	while(m--) {
		int idx;
		cin >> idx;
		rem[idx-1]++;
	}	
	int l = str.length();
	for(int i = 1;i < l;i++) {
		rem[i] += rem[i-1];
	}
	for(int i = 0;i < l;i++) {
		if(i < l/2) {
			cout << (rem[i]%2 ? str[l-i-1] : str[i]);
		}else {
			cout << (rem[l-i-1]%2 == 0 ? str[i] : str[l-i-1]);
		}
	}
	return 0;
}