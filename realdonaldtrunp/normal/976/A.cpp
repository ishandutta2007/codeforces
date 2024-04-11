#include "bits/stdc++.h"
using namespace std;

int n;

char buf[102];

int cnt[2];
string s;
int main() {
	cin >> n;
	scanf("%s", buf);
	s = buf;
	for (int i = 0; i < s.size(); i++) {
		cnt[s[i] - '0']++;
	}
		if(cnt[1])cout << "1";
		for (int i = 0; i < cnt[0]; i++) {
			cout << "0";
		}
		cout << endl;
	
	return 0;
}