#include <iostream>

using namespace std;

int K;

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> K;
	if(K>=37){
		cout << "-1" << endl;
		return 0;
	}
	while(K>1){
		K-=2;cout << "8";
	}
	while(K>0){
		--K;cout << "9";
	}
	cout << endl;
	
	return 0;
}