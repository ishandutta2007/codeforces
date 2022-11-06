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

int C;
string S;
stack<int> st;

void yeet() {
	cout << "Impossible\n";
	exit(0);
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> S;
	for (char c : S) {
		if (c == '<' || c == '{' || c == '[' || c == '(') st.push(c);
		else if (st.empty()) yeet();
		else {
			if (c == '>' && st.top() != '<') C++;
			else if (c == ')' && st.top() != '(') C++;
			else if (c == ']' && st.top() != '[') C++;
			else if (c == '}' && st.top() != '{') C++;
			st.pop();
		}
	}
	if (!st.empty()) yeet();
	cout << C << '\n';
}