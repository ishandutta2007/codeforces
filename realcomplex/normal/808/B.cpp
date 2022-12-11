#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	
	int n,k;
	cin >> n >> k;
	ll sk[n + 1];
	ll sum = 0;
	ll ska;
	sk[0] = 0;
	for(int i = 1;i<=n;i++){
		cin >> ska;
		sum += ska;
		sk[i] = sum;
	}
	long double total = 0;
	int p = 0;
	for(int i = k;i<=n;i++){
		total += sk[i] - sk[p];
		p++;
	}
	total /= (n - k) + 1;
	cout << setprecision(20) << total;
	return 0;
}