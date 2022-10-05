#include <iostream>
#include <vector>
using namespace std;

int n, a[2][1000], p[1000];
bool used[1001];

void printp() {
	for (int i = 0; i < n; i++) cout << p[i] << " "; cout << endl;
}

int findnotused() {
	for (int i = 1; i <= n; i++)
		if (!used[i]) return i;
	return 0;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[0][i];
	for (int i = 0; i < n; i++) cin >> a[1][i];
	for (int i = 0; i < n; i++) used[i + 1] = false;
	vector<int> unplaced;
	for (int i = 0; i < n; i++)
		if (a[0][i] == a[1][i])
			used[a[0][i]] = true, p[i] = a[0][i];
		else
			unplaced.push_back(i);
	if (unplaced.size() == 1) {
		p[unplaced[0]] = findnotused();
		printp();
		return 0;
	}
	if (used[a[0][unplaced[0]]])
		p[unplaced[0]] = a[1][unplaced[0]], used[a[1][unplaced[0]]] = true, p[unplaced[1]] = findnotused(), printp();
	else if (used[a[1][unplaced[0]]])
		p[unplaced[0]] = a[0][unplaced[0]], used[a[0][unplaced[0]]] = true, p[unplaced[1]] = findnotused(), printp();
	else if (used[a[0][unplaced[1]]])
		p[unplaced[1]] = a[1][unplaced[1]], used[a[1][unplaced[1]]] = true, p[unplaced[0]] = findnotused(), printp();
	else
		p[unplaced[1]] = a[0][unplaced[1]], used[a[0][unplaced[1]]] = true, p[unplaced[0]] = findnotused(), printp();
}