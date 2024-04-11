#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int s, n;

void solve() {
	cin >> s >> n;
	vector<int> dig;
	int sum=0;
	int s2=s;
	while(s2) {
		dig.push_back(s2%10);
		sum+=s2%10;
		s2/=10;
	}
	while(sum<n) {
		int pos=1;
		while(!dig[pos])
			++pos;
		--dig[pos];
		dig[pos-1]+=10;
		sum+=9;
	}
	while(n>1) {
		--n;
		int pos=0, num=1;
		while(!dig[pos])
			++pos, num*=10;
		--dig[pos];
		cout << num << " ";
	}
	int num=0;
	for (int i=0, v=1; i<dig.size(); ++i, v*=10) {
		assert(dig[i]<10);
		num+=dig[i]*v;
	}
	cout << num << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}