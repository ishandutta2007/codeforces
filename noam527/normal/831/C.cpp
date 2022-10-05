#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main() {
	set<int> alloptions;
	map<int, int> needed;
	int k, n, a[2000], b[2000], v1, c[2000];
	cin >> k >> n;
	for (int i = 0; i < k; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i], needed[b[i]]++;
	for (int i = 0; i < k; i++) {
		int cnt = 0;
		map<int, int> tneeded = needed;
		for (int j = 0; j < k; j++) c[j] = a[j];
		c[i] = b[0];
		for (int j = i - 1; j >= 0; j--) c[j] = c[j + 1] - a[j + 1];
		for (int j = i + 1; j < k; j++) c[j] = c[j - 1] + a[j];
		for (int j = 0; j < k; j++) if (tneeded[c[j]] > 0) tneeded[c[j]]--, cnt++;
		if (cnt == n) alloptions.insert(c[0] - a[0]);
	}
	cout << alloptions.size() << endl;
}