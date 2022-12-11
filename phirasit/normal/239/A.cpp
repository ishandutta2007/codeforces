#include <iostream>

int y,k,n;

using namespace std;

int main() {
	int i;
	bool check = false;
	cin >> y >> k >> n;
	for(i=k;i<=n;i+=k) {
		if(i-y >= 1) {
			cout << i-y << " ";
			check = true;
		}
	}
	if(check == false)
		cout << "-1";
	cout << endl;
	return 0;
}