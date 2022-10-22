#include <bits/stdc++.h>
using namespace std;

string S;
vector<int> opens, closes;
vector<int> l, r;

int main() {
	cin >> S;
	for (int i = 0; i < S.length(); i++) {
		if (S[i] == '(') opens.push_back(i);
		else closes.push_back(i);
	}
	if (opens.size() == 0 || closes.size() == 0 || opens[0] > closes.back()) {
		printf("0\n");
		return 0;
	}
	for (int i = 0; i < S.length(); i++) {
		if (i >= opens.size() || i >= closes.size()) break;
		int lidx = opens[i], ridx = closes[closes.size() - 1 - i];
		if (lidx > ridx) break;
		l.push_back(lidx + 1);
		r.push_back(ridx + 1);
	}
	printf("%d\n", 1);
	printf("%d\n", l.size() * 2);
	for (int i = r.size() - 1; i >= 0; i--) l.push_back(r[i]);
	for (int i = 0; i < l.size(); i++) {
		if (i) printf(" ");
		printf("%d", l[i]);
	}
	printf("\n"); 
}