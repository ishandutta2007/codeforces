/*
_NUUUUUUU_
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<iterator>
#include<map>
using namespace std;

#define pb push_back
typedef long long ll;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	map<string, int> m;
	for (int i = 0; i < n; i++) {
		string s, t;
		cin >> t >> s;
		while ((int)s.size() < 18) {
			s = "0" + s;
		}
		if (t == "?") {
			cout << m[s] << endl;
			continue;
		}
		for (int i = 0; i < 18; i++) {
			if (((int)s[i] - 48) % 2 == 0) {
				s[i] = '0';
			}
			else {
				s[i] = '1';
			}
		}
		if (t == "+") {
			m[s]++;
		}
		if (t == "-") {
			m[s]--;
		}
	}
}