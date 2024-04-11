#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int f(int x) {
	int ans=0;
	for (int i=2; i*i<=x; ++i)
		while(x%i==0)
			++ans, x/=i;
	ans+=x>1;
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int a, b, k;
		cin >> a >> b >> k;
		int x=f(a), y=f(b);
		if (k==1) {
			cout << ((a%b==0||b%a==0)&&a^b?"Yes":"No") << "\n";
		} else {
			cout << (k<=x+y?"Yes":"No") << "\n";
		}
	}
	return 0;
}