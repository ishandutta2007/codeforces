#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define int long long

string S;
int U, un[5005];

string gs(int x) {
	string r = "";
	for (int i = x; i < S.size(); i++) r.push_back(S[i]);
	for (int i = 0; i < x; i++) r.push_back(S[i]);
	return r;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> S;
	for (char i = 'a'; i <= 'z'; i++) {
		int M = 0;
		vector<string> V;
		for (int j = 0; j < S.size(); j++)
			if (S[j] == i) V.push_back(gs(j));
		for (int j = 0; j < S.size(); j++) {
			int C = 0, cnt[30] = {};
			for (auto &i : V)
				cnt[i[j] - 'a']++;
			for (int k = 0; k < 26; k++)
				if (cnt[k] == 1) C++;
			M = max(M, C);
		}
		U += M;
	}
	cout << fixed << setprecision(20) << (long double)(U) / (long double)S.size() << '\n';
}