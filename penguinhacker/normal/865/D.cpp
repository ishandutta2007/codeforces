#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	ll ans=0;
	priority_queue<int, vector<int>, greater<int>> dif;
	while(n--) {
		int p;
		cin >> p;
		ans-=p;
		dif.push(p);
		if (dif.top()<p) {
			dif.pop();
			dif.push(p);
		}
	}
	for (; dif.size(); ans+=dif.top(), dif.pop());
	cout << ans;
	return 0;
}