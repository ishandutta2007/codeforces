#include <iostream>
using namespace std;

int main() {
	char d;
	string heidi = "heidi";
	while(cin >> d){
		if(heidi.size() > 0){
			if(d == heidi[0]){
				heidi.erase(0,1);
			}
		}
		
	}
	if(heidi.size() == 0){
		cout << "YES";	
	}
	else{
		cout << "NO";
		
	}
	return 0;
}