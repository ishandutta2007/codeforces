#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	
	int n;
	cin >> n;
	ll sk[n];
	ll op = 0;
	ll req = 1;
	for(int i = 0;i<n;i++){
		cin >> sk[i];
	}
	sort(sk,sk+n);
	for(int i = 0;i<n;i++){
		op += abs(sk[i] - req);
		req++;
	}
	cout << op;
	return 0;
}