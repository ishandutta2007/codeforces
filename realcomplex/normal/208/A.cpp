#include <iostream>
using namespace std;

int main() {
	string n;
	cin >> n;
	for(int i = 3;i<=n.size();i++){
		if(n.substr(i - 3,3) == "WUB"){
			n.insert(i - 3," ");
			n.erase(i - 2,3);
			i--;
		}
	}
	cout << n;
	return 0;
}