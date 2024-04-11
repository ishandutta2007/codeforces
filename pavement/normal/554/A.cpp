#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
typedef long double ld;

string S;
set<string> st;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		// put before i
		for (char k = 'a'; k <= 'z'; k++) {
			string cpy = "";
			for (int j = 0; j < i; j++) cpy.pb(S[j]);
			cpy.pb(k);
			for (int j = i; j < S.size(); j++) cpy.pb(S[j]);
			st.insert(cpy);
		}
	}
	for (char k = 'a'; k <= 'z'; k++) {
		string cpy = S;
		cpy.pb(k);
		st.insert(cpy);
	}
	cout << st.size() << '\n';
}