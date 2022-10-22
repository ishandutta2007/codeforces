#include <bits/stdc++.h>
using namespace std;

string s[7] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
	string a, b;
	cin >> a >> b;
	int f = -1, sc = 0;
	for (int i = 0; i < 7; i++) if (a == s[i]) f = i;
	for (int i = 0; i < 7; i++) if (b == s[i]) sc = i;
	bool b1 = 0;
	for (int i = 0; i < 11; i++) {
		
		if ((f + days[i]) % 7 == sc) b1 = 1;
	}
	if (b1) printf("YES\n");
	else printf("NO\n");
}