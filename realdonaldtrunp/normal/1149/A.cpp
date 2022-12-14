#include"bits/stdc++.h"
#include "chrono"
using namespace std;
typedef long long ll;

int n;

vector<int> ans;

int main() {
	cin >> n;
	int one = 0;
	int two = 0;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		if (a == 1) {
			one++;
		}
		else {
			two++;
		}
	}
	if (two) {
		two--;
		ans.push_back(2);
	}
	if (one) {
		one--;
		ans.push_back(1);
	}
	while (two) {
		two--;
		ans.push_back(2);
	}
	while (one) {
		one--;
		ans.push_back(1);
	}
	for (int i = 0; i < ans.size(); i++) {
		if (i)printf(" ");
		printf("%d", ans[i]);
	}
	puts("");
	return 0;
}