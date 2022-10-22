#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

string s;
vector<int> v1, v2;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	for (int i=0; i<s.size()-1; ++i) {
		if (s[i] == 'A' && s[i+1] == 'B')
			v1.push_back(i);
		else if (s[i] == 'B' && s[i+1] == 'A')
			v2.push_back(i);
	}
	
	if (v1.empty() || v2.empty() || (v1.size() == 1 && v2.size() == 1 && abs(v1[0]-v2[0]) == 1))
		cout << "NO";
	else if ((v1.size() == 2 && v2.size() == 1 && (v2[0] == v1[0]+1) && (v1[1] == v2[0]+1))
				|| (v1.size() == 1 && v2.size() == 2 && (v1[0] == v2[0]+1) && (v2[1] == v1[0]+1)))
		cout << "NO";
	else
		cout << "YES";
	return 0;
}