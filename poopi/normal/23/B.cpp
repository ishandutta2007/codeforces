#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
	string str;
	int T, n;
	for(cin >> T; T--; ){
		cin >> n;
		cout << max(0, n - 2) << endl;
	}
	return 0;
}