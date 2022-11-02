#include <bits/stdc++.h>

using namespace std;

#define MAX_A 50000

bitset<MAX_A * 25> dp[30];

int res[3][100];

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	multiset<int> m;
	
	int n;
	cin >> n;
	for (int a, i = 0; i < 2 * n; i++) {
		cin >> a;
		m.insert(a);
	}
	
	res[1][1] = *m.begin();
	m.erase(m.begin());
	res[2][n] = *m.begin();
	m.erase(m.begin());
	
	dp[0][0] = true;
	int sum = 0;
	for (int i : m) {
		sum += i;
		for (int j = n - 1; j > 0; j--) {
			dp[j] |= (dp[j - 1] << i);
		}
	}
	//cout << "koniec" << endl;
	//cout << sum << endl;
	
	sum /= 2;
	int gdzie, poz = n - 1;
	for (int i = sum; ; i--) {
		if (dp[poz][i]) {
			gdzie = i;
			break;
		}
	}
	//cout << "sdf" << endl;
	
	vector<int> v;
	int li = 30;
	while (poz && li--) {
		//cout << poz << " " << gdzie << endl;
		for (auto it = m.begin(); it != m.end(); it++) {
			if (*it > gdzie) continue;
			if (dp[poz - 1][gdzie - *it]) {
				v.push_back(*it);
				gdzie -= *it;
				poz--;
				m.erase(m.find(*it));
				//cout << "good" << endl;
				break;
			}
		}
	}
	
	sort(v.begin(), v.end());
	
	for (int i = 0; i < v.size(); i++) {
		res[1][i + 2] = v[i];
	}
	
	int i = n - 1;
	for (int j : m) {
		res[2][i] = j;
		i--;
	}
	
	for (int i = 1; i <= 2; i++) {
		for (int j = 1; j <= n; j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
/*
25
24114 46559 40804 40930 39129 49505 18453 33358 22440 29777 37814 35048 41988 47225 12324 47524 47055 14565 46508 14139 14908 19912 16369 22323 11922
45809 30314 23813 39806 37964 25473 14603 24414 32187 42137 30819 14382 47520 11653 21851 25587 14420 24131 32070 19898 13019 49551 20925 34197 38847
*/