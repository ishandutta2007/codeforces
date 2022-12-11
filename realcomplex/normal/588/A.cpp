#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int ned,c_;
	int min_cost = 1000000;
	int sum = 0;
	for(int i = 0;i<n;i++){
		cin >> ned >> c_;
		if(c_ < min_cost){
			min_cost = c_;
		}
		sum += ned * min_cost;
	}
	cout << sum;
	return 0;
}