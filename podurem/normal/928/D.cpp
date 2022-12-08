#include <bits/stdc++.h>
 
using namespace std;

const int dd = (int)1e6 + 1;

int G[dd][26], V, p[dd], cnt = 2, Y[dd], kon[dd];
vector<string> R;
int ans = 0;

int get(char c) {
	if (G[V][c - 'a'] != 0)
		V = G[V][c - 'a'];
	else {
		G[V][c - 'a'] = cnt;
		p[cnt] = V;
		Y[cnt] = 0;
		V = cnt++;
	}
	return Y[V];
}

void add(string s) {
	V = 1;
	for (int i = 0; i < (int)s.size(); ++i) {
		++ans;
		int S = get(s[i]);
		if (S > 0 && i != (int)R[S].size() - 1) {
			if ((int)s.size() >= (int)R[S].size() && R[S] == string(s.begin(), s.begin() + (int)R[S].size())) {
				++ans;
				for (int j = i + 1; j < (int)R[S].size(); ++j)
					get(s[j]);
				i = (int)R[S].size() - 1;
			} else {
				for (int j = i + 1; j < (int)s.size(); ++j) {
					++ans;
					get(s[j]);
				}
				kon[V] = 1;
				int X = (int)R.size();
				if (Y[V] == 0) R.push_back(s);
				while (V != 0) {
					if (Y[V] == 0) Y[V] = X;
					else Y[V] = -1;
					V = p[V];
				}
				return;
			}
		}
	}
	if (kon[V] == 0) {
		kon[V] = 1;
		int X = (int)R.size();
		if (Y[V] == 0) R.push_back(s);
		while (V != 0) {
			if (Y[V] == 0) Y[V] = X;
			else Y[V] = -1;
			V = p[V];
		}
	}
}

int main() {
	R.push_back("DiCkLo");
	string s, s1 = "";
	while (getline(cin, s)) {
		s += '.';
		for (int i = 0; i < (int)s.size(); ++i)
			if (s[i] < 'a' || s[i] > 'z') {
				if (s1 != "") {
					add(s1);
					s1 = "";
				}
				++ans;
			} else
				s1 += s[i];
	}
	cout << ans;
    return 0;
}