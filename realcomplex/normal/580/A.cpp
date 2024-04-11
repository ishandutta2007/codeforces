#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int num;
	int sk = 1;
	int mx = 1;
	int last;
	cin >> last;
	for(int i = 1;i<n;i++){
		cin >> num;
		if(num >= last){
			sk++;
			if(sk > mx){
				mx = sk;
			}
		}
		else{
			sk = 1;
		}
		last = num;
	}
	cout << mx;
	return 0;
}