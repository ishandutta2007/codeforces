#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n, m, visited[100];
string s[100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		visited[i] = 0;
		cin >> s[i];
	}
	
	string pal;
	bool hasPal = 0;
	int length = 0;
	string t = "";

	for (int i=0; i<n; ++i) {
		if (visited[i])
			continue;
		bool hasPair = 0;
		for (int j=i+1; j<n; ++j) {
			if (visited[j])
				continue;
			string r = s[j];
			reverse(r.begin(), r.end());
			if (s[i] == r) {
				length += 2*m;
				hasPair = 1;
				break;
			}
		}
		if (hasPair)
			t += s[i];
		else if (!hasPal) {
			string r = s[i];
			reverse(r.begin(), r.end());
			if (s[i] == r) {
				length += m;
				hasPal = 1;
				pal = s[i];
			}
		}
	}
	
	string t2 = t;
	reverse(t2.begin(), t2.end());
	if (hasPal) {
		t = t + pal + t2;
	}
	else {
		t = t + t2;
	}

	cout << length << '\n' << t << '\n';
	return 0;
}