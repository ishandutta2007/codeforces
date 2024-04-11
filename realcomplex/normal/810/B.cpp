#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	
	int n,f;
	cin >> n >> f;
	ll sk[n][4];
	ll preces;
	ll sum = 0;
	int ak[n];
	for(int i = 0;i<n;i++){
		cin >> sk[i][0] >> sk[i][1];
		sk[i][2] = min(sk[i][0],sk[i][1]);
		sum += sk[i][2];
		preces = sk[i][0] * 2;
		sk[i][3] = min(sk[i][1],preces) - sk[i][2];
		ak[i] = sk[i][3];
	}
	sort(ak,ak + n);
	for(int i = n - 1;i>=n - f ;i--){
		sum += ak[i];
	}
	cout << sum;
	return 0;
}