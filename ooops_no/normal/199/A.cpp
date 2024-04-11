/*
_NUUUUUUU_
*/

#include<iostream>
#include<algorithm>
#include<vector>;
#include<map>
#include<set>
#include<queue>

using namespace std;

#define ll long long


int main()
{
	ll n;
	cin >> n;
	vector <int> l;
	l.push_back(1);
	l.push_back(0);
	l.push_back(1);
	l.push_back(1);
	if (n <= 3) {
		int cnt = 0;
		while (n != 0) {
			cout << 1 << " " ;
			cnt++;
			n--;
		}
		while (cnt != 3) {
			cout << 0 << " ";
			cnt++;
		}
		return 0;
	}
	int i = 3;
	while (l[i - 1] + l[i] < n) {
		l.push_back(l[i - 1] + l[i]);
		i++;
	}
	int a = 3;
	int cnt = 1;
	vector<int> ans;
	while (i!=0 && n!=0) {
		if (n - l[i] == 0 && cnt == 3) {
			ans.push_back(l[i]);
			continue;
		}
		if (n - l[i] >= 3 - cnt) {
			ans.push_back(l[i]);
			n -= l[i];
		}
		cnt++;
		i--;
	}
	if (ans.size() != 3) {
		cout << "I'm too stupid to solve this problem";
		return 0;
	}
	for (int i = 0; i < 3; i++) {
		cout << ans[i] << " ";
	}
}