#include <bits/stdc++.h>
using namespace std;

string a, b;
int N;

int main() {
	cin >> a >> b;
	cin >> N;
	printf("%s %s\n", a.c_str(), b.c_str());
	for (int i = 0; i < N; i++) {
		string m, r;
		cin >> m >> r;
		if (a == m) {
			a = r;
		} else b = r;
		printf("%s %s\n", a.c_str(), b.c_str());
	}
}