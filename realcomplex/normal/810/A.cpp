#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int n,k;
	cin >> n >> k;
	float sum = 0;
	int sk = 0;
	for(int i = 0;i<n;i++){
		cin >> sk;
		sum += sk;
	}
	int r = n;
	while(round(sum / n) < k ){
		n++;
		sum += k;
	}
	cout << n - r;
	return 0;
}