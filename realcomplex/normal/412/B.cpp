#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	int s[n];
	for(int j = 0;j<n;j++)cin >> s[j];
	sort(s,s+n);
	cout << s[n-k] << "\n";
	return 0;
}