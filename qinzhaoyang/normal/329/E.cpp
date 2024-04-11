#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
typedef long long ll;

struct Node {int x, y, c;} o[N];

inline int cmp(Node a, Node b) {
	return a.x < b.x;
}

int n;
ll mx11, mx12, mx21, mx22;

ll calc1() {
	ll ret = 0;
	for (int i = 1; i <= n / 2; i++) {
		ret -= 2ll * o[i].x;
		ret += 2ll * o[n - i + 1].x;
	}
	return ret;
}

ll calc2() {
	ll ret = 0;
	for (int i = 1; i < n / 2; i++) {
		ret -= 2ll * o[i].x;
		ret += 2ll * o[n - i + 1].x;
	}
	if (n % 2 == 1) {
		int t = n / 2 + 1;
		ret += 2ll * max(-o[t].x + o[t + 1].x, -o[t - 1].x + o[t].x);
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &o[i].x, &o[i].y);
	sort (o + 1, o + n + 1, cmp);
	mx11 = calc1(), mx12 = calc2();
	if (n % 2 == 0) {
		for (int i = 1; i <= n / 2; i++)
			o[i].c = 1;
	}
	else {
		for (int i = 1; i <= n / 2; i++)
			o[i].c = -1, o[n - i + 1].c = 1;
	}
	for (int i = 1; i <= n; i++)
		swap(o[i].x, o[i].y);
	sort (o + 1, o + n + 1, cmp);
	mx21 = calc1(), mx22 = calc2();
	if (n % 2 == 0) {
		int flag = 1;
		for (int i = 1; i <= n / 2; i++)
			if (o[i].c != o[1].c) flag = 0;
		if (flag == 1) printf("%lld\n", mx11 + mx21);
		else printf("%lld\n", max(mx11 + mx22, mx21 + mx12));
	}
	else {
		int t = n / 2 + 1;
		if (o[t].c != 0) printf("%lld\n", mx11 + mx21);
		else {
			int flag = 1;
			for (int i = 1; i <= n / 2; i++)
				if (o[i].c != o[1].c) flag = 0;
			if (flag == 1) printf("%lld\n", mx11 + mx21);
			else printf("%lld\n", max(mx11 + mx22, mx21 + mx12));
		}
	}
	return 0;
}