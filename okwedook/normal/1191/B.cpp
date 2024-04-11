#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define f first
#define s second

void answer(int x) {
	cout << x;
	exit(0);
}

int main()
{
	vector<pair<int, char>> a(3);
	for (auto &i : a) cin >> i.f >> i.s;
	sort(a.begin(), a.end());
	if (a[0].s == a[1].s && a[1].s == a[2].s && (a[1].f - a[0].f == 1 && a[2].f - a[1].f == 1 || a[1].f - a[0].f == 0 && a[2].f - a[1].f == 0))  answer(0);
	for (int i = 0; i < 3; ++i)
		for (int j = i + 1; j < 3; ++j) 
			if (a[i].s == a[j].s && a[j].f - a[i].f <= 2) answer(1);
	answer(2);
	return 0;
}