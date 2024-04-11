#include"bits/stdc++.h"

using namespace std;

#define MAX 500002

char buf[MAX];
string s;
string t;

int nex[MAX];

int cnt;
int cnt2;

string ans;

int main() {
	scanf("%s", buf);
	s = buf;
	scanf("%s", buf);
	t = buf;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') {
			cnt++;
		}
		else {
			cnt2++;
		}
	}
	{
		int i = 0;
		int j = -1;
		nex[0] = -1;
		while (i < t.size()) {
			while (j >= 0 && t[j] != t[i]) {
				j = nex[j];
			}
			i++;
			j++;
			nex[i] = j;
		}
	}
	int j = 0;
	for (int i = 0; i < s.size(); i++) {
		int want = t[j] - '0';
		if (want == 1 && cnt2 == 0) {
			break;
		}
		if (want == 0 && cnt == 0) {
			break;
		}
		if (want == 1) {
			cnt2--;
			ans.push_back('1');
			
		}
		else {
			cnt--;
			ans.push_back('0');
		}
		j++;
		if (j == t.size()) {
			j = nex[j];
		}
	}
	while (cnt) {
		ans.push_back('0');
		cnt--;
	}
	while (cnt2) {
		ans.push_back('1');
		cnt2--;
	}
	printf("%s\n", ans.c_str());
	return 0;
}