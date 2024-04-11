#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <string>
#define mp make_pair

using namespace std;

char buf1[200001];
char buf2[200001];

string solve(char* buf, int l, int r) {
	if ((r - l) % 2 == 1) {
		return string(buf + l, r - l);
	}
	int mid = (l + r) / 2;
	string s1 = solve(buf, l, mid);
	string s2 = solve(buf, mid, r);
	if (s1.compare(s2) > 0) {
		return s1.append(s2);
	}
	else return s2.append(s1);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s", buf1);
	scanf("%s", buf2);
	int n = strlen(buf1);
	string s1 = solve(buf1, 0, n);
	string s2 = solve(buf2, 0, n);
	if (s1 == s2)puts("YES");
	else puts("NO");
	return 0;
}