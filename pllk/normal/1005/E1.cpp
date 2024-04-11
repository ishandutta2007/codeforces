#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

int n, m;
int p[202020];
int d[202020];
map<int,int> u;
ll z;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> p[i];
	int c = 0;
	for (int i = 1; i <= n; i++) {
		if (p[i] > m) c++;
		if (p[i] < m) c--;
		d[i] = c;
	}
	for (int i = n; i >= 1; i--) {
		u[d[i]]++;
		if (p[i] == m) break;
	}
	for (int i = 1; i <= n; i++) {
		int a = d[i];
		int b = d[i]+1;
		if (p[i] > m) {a--; b--;}
		if (p[i] < m) {a++; b++;}
		z += u[a];
		z += u[b];
		if (p[i] == m) break;
	}
	cout << z << "\n";
}