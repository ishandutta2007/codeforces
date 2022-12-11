#include <iostream>
using namespace std;

int main() {
	
	int n;
	cin >> n;
	string vards;
	for(int x = 0;x<n;x++){
		cin >> vards;
		if(vards.size() > 10){
			cout << vards[0] << vards.size() - 2 << vards[vards.size() - 1] << "\n";
		}
		else{
			cout << vards << "\n";
		}
	}
	return 0;
}