#include <vector>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

struct comn {
	int x, y, z;
};

struct oboi {
	int len, wid, cost;
};

int n, m;
comn a[1000];
oboi b[1000];
//
long long cost(int x, int y) {
	long long p = (a[x].x+a[x].y)*2;
	long long vis = a[x].z;
	long long num_of_pol = b[y].len / a[x].z;
	if (num_of_pol == 0) return 1e9;
	long long need_pol = 1+(p-1)/b[y].wid;
	long long need = 1+(need_pol-1)/num_of_pol;
	return need*b[y].cost;
};
//
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i].x >> a[i].y >> a[i].z;
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> b[i].len >> b[i].wid >> b[i].cost;
	//
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		long long min_cost = 1e9;
		for (int j = 0; j < m; j++)
			if (cost(i, j) < min_cost)
				min_cost = cost(i, j);
		sum += min_cost;
	}
	cout << sum << endl;
}