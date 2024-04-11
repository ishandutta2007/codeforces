#include <bits/stdc++.h>
using namespace std;
typedef long long Long;

string s;
int now = 0, cntA, cntB, cntC;

int main() {
	cin >> s;
	for (int i = 0; i < s.size(); ++i)
		if (now == 0) {
			if (s[i] == 'a') ++cntA;
			else if (s[i] == 'b') {
				++cntB; now = 1;
			} else {
				printf("NO"); return 0;
			}
		} else if (now == 1){
			if (s[i] == 'b') ++cntB;
			else if (s[i] == 'c'){
				++cntC; now = 2;
			} else {
				printf("NO"); return 0;
			}
		} else if (now == 2) {
			if (s[i] == 'c') ++cntC;
			else {
				printf("NO"); return 0;
			}
		}
	if (cntA && cntB && (cntC == cntA || cntC == cntB)) printf("YES");
	else printf("NO");
}