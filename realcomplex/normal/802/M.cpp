#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,k;
	cin >> n >> k;
	int sk[n];
	for(int i = 0;i< n;i++){
		cin >> sk[i];
	}
	sort(sk,sk + n);
	int sum = 0;
	for(int i = 0;i<k;i++){
		sum += sk[i];
	}
	cout << sum;
	return 0;
}