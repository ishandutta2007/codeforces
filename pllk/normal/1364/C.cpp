#include <iostream>
#include <vector>

using namespace std;

int n;
int a[101010];
int b[101010];
int c[101010];

void rip() {
	cout << "-1\n";
	exit(0);
}

int main() {
	int n;
	cin >> n;
	vector<int> v;
	int k = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] < a[i-1]) rip();
		if (a[i] == a[i-1]) {
			v.push_back(i);
		} else {
			b[i] = a[i-1];
			c[b[i]] = 1;
			while (k <= a[i]-1) {
				if (c[k]) k++;
				else if (v.size()) {
					b[v.back()] = k;
					k++;
					v.pop_back();
				}
				else rip();
			}
		}
	}
	while (v.size()) {
		b[v.back()] = 1000000;
		v.pop_back();
	}
	for (int i = 1; i <= n; i++) cout << b[i] << " ";
	cout << "\n";
}