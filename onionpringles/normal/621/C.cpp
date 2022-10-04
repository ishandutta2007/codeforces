
#pragma warning(disable:4996)

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>
#include <set>
#define mp make_pair
#define ni(n) scanf("%d", &(n))

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

double prob[100000];

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; ni(n);
	int p; ni(p);
	for (int i = 0; i < n; i++) {
		int l, r;
		ni(l); ni(r);
		int num = r / p - (l - 1) / p;
		prob[i] = (double)num / (r - l + 1);
	}
	double exp = 0;
	for (int i = 0; i < n; i++) {
		int ni = (i + 1) % n;
		exp += prob[i] + prob[ni] - prob[i] * prob[ni];
	}

	printf("%.15f", exp * 2000);
	return 0;
}
/*#pragma warning(disable:4996)

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>
#include <set>
#define mp make_pair
#define ni(n) scanf("%d", &(n))

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<int> pos;
vector<int> neg;

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; ni(n);
	for (int i = 0; i < n; i++) {
		int x, y;
		ni(x); ni(y);
		pos.push_back(x + y);
		neg.push_back(x - y);
	}
	sort(pos.begin(), pos.end());
	sort(neg.begin(), neg.end());
	ll cnt = 0; int curcnt = 1; int cur = pos[0];
	for (int i = 1; i < n; i++) {
		if (pos[i] == cur) {
			curcnt++;
		}
		else {
			cnt += (ll)curcnt*(curcnt - 1) / 2;
			curcnt = 1;
			cur = pos[i];
		}
	}
	cnt += (ll)curcnt*(curcnt - 1) / 2;

	curcnt = 1; cur = neg[0];
	for (int i = 1; i < n; i++) {
		if (neg[i] == cur) {
			curcnt++;
		}
		else {
			cnt += (ll)curcnt*(curcnt - 1) / 2;
			curcnt = 1;
			cur = neg[i];
		}
	}
	cnt += (ll)curcnt*(curcnt - 1) / 2;
	printf("%I64d", cnt);
	return 0;
}*/