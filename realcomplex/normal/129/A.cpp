#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	cin >> n;
	int sk[n];
	int sum = 0;
	for(int i = 0;i<n;i++){
		cin >> sk[i];
		sum += sk[i];
	}
	int ways = 0;
	for(int i = 0;i<n;i++){
		sum -= sk[i];
		if(sum % 2 == 0){
			ways++;
		}
		sum += sk[i];
	}
	cout << ways;
	return 0;
}