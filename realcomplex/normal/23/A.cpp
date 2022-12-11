#include <iostream>
using namespace std;

int main() {
	string n;
	cin >> n;
	int mx = 0;
	string s;
	for(int i = 0;i<n.size();i++){
		for(int x = 1;x<n.size();x++){
			s = n.substr(i,x);
			for(int y = i + 1;y<n.size();y++){
				if(n.substr(y,x) == s){
					if(x > mx){
						mx = x;
					}
				}
			}
		}
	}
	cout << mx;
	return 0;
}