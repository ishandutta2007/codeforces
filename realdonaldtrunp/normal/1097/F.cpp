#include"bits/stdc++.h"
using namespace std;

#define MAX 100002

int n;
int q;
bool use[7002];
vector<long long int> pr;
bitset<7001> d[MAX];
bitset<7001> z[MAX];
bitset<7001> s[MAX];
string ans;

int main() {
	cin >> n >> q;
	for (int i = 2; i <= 7000; i++) {
		if (use[i] == false) {
			pr.push_back(i);
			for (int j = i * 2; j <= 7000; j += i) {
				use[j] = true;
			}
		}
	}
	for (int i = 1; i <= 7000; i++) {
		for (int j = i; j <= 7000; j += i) {
			z[j].set(i, true);
			s[i].set(j, true);
		}
		for (int k = 0; pr[k] * pr[k] * i <= 7000; k++) {
			for (int j = pr[k] * pr[k] * i; j <= 7000; j += i*pr[k]*pr[k]) {
				s[i].set(j, false);
			}
		}
	}
	
	while (q--) {
		int ty;
		scanf("%d", &ty);
		if (ty == 1) {
			int a, b;
			scanf("%d%d", &a, &b);
			a--;
			d[a] = z[b];
			continue;
		}
		if (ty == 2) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			a--;
			b--;
			c--;
			d[a] = d[b] ^ d[c];
			continue;
		}
		if (ty == 3) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			a--;
			b--;
			c--;
			d[a] = d[b] & d[c];
			continue;
		}
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		if ((d[a] & s[b]).count() % 2) {
			ans.push_back('1');
		}
		else {
			ans.push_back('0');
		}
	}
	printf("%s", ans.c_str());
	puts("");
	return 0;
}