#include <iostream>
using namespace std;

int main() {
	int m,d;
	int n;
	cin >> n;
	int sk1 = 0,sk2 = 0;
	for(int i = 0;i<n;i++){
		cin >> m >> d;
		if(m > d){
			sk1++;
		}
		if(d > m){
			sk2++;
		}
	}
	if(sk1 == sk2){
		cout << "Friendship is magic!^^";
	}
	else if(sk2 > sk1){
		cout << "Chris";	
	}
	else{
		cout << "Mishka";
	}
	return 0;
}