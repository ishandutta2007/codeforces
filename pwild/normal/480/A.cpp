#include <algorithm>
#include <iostream>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)

struct Ex {
	int a, b;
};

Ex e[5000];

bool cmp(const Ex &x, const Ex &y) {
	return (x.a < y.a || (x.a == y.a && x.b < y.b));
}


int main() {
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	FOR(i, 0, n) cin >> e[i].a >> e[i].b;
	sort(e, e + n, cmp);

	int cur = e[0].b;
	FOR(i, 1, n) {
		if (e[i].b >= cur) cur = e[i].b;
		else cur = e[i].a;
	}
	cout << cur << endl;

}