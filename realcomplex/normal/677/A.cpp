#include <iostream>
using namespace std;

int main() {
	
	int n,m;
	cin >> n >> m;
	int sum = 0;
	int sk;
	for(int i = 0;i<n;i++){
		cin >> sk;
		if(sk > m){
			sum+=2;
		}
		else{
			sum++;
		}
	}
	cout << sum;
	return 0;
}