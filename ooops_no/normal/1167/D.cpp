#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<iterator>
#include<map>
#include<deque>
#include<math.h>
#include <numeric> 
using namespace std;

#define int long long
#define pb push_back

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	deque<int> q;
	int l = 0;
	vector<int> used(n);
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			l++;
			q.push_back(i);
		}
		else {
			l--;
			used[i] = (l + 1) % 2;
			used[q.back()] = (l + 1) % 2;
			q.pop_back();
		}
	}
	for (auto to : used) {
		cout << to;
	}
}