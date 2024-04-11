#include <iostream>
using namespace std;

int main() {
	int n,t;
	cin >> n >> t;
	t--;
	int cur = 0;
	bool can = false;
	int sk;
	for(int i = 0;i<n;i++){
		cin >> sk;
		if(cur == t){
			can = true;
		}
		if(i == cur){
			cur += sk;
		}
	}
	if(can == true){
		cout << "YES";
	}
	else{
		cout << "NO";
	}
	return 0;
}