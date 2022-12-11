#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	char s;
	int d = 0,a = 0;
	for(int i = 0;i<n;i++){
		cin >> s;
		if(s == 'A'){
			a++;
		}
		else{
			d++;
		}
	}
	if(a == d){
		cout << "Friendship";
	}
	else if(a > d){
		cout << "Anton";
	}
	else{
		cout << "Danik";
	}
	return 0;
}