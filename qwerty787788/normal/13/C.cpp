#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define MAX 5555
#define pb push_back
#define MAX_VALUE 1000000000000000000LL
#define MIN_VALUE -MAX_VALUE
int a[MAX];
long long res[2][MAX];

int nextInt() {
	int tmp;
	scanf("%d", &tmp);
	return tmp;
}

int main ()
{
		int n = nextInt();
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		vector<int> values;
		for (int x  = 0; x < n; x++)
			values.pb(a[x]);
		sort(values.begin(), values.end());
		vector<int> values2;
		long long last = MIN_VALUE;
		for (int i = 0; i< n;i++) {
			if (last != values[i])
				values2.pb(values[i]);
			last = values[i];
		}
		int all[values2.size()];
		int it = 0;
		for (int x  = 0; x < values2.size(); x++) {
			all[it++] = values2[x];
		}
		int id[n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < it; j++)
				if (a[i] == all[j])
					id[i] = j;
		}
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < it; j++)
				res[i][j] = MAX_VALUE;
		for (int i = 0; i < it; i++) {
			res[1][i] = abs(all[id[0]] - all[i]);
		}
		for (int pos = 0; pos < n; pos++) {
			for (int value = 0; value < it; value++) {
				res[0][value] = res[1][value];
				res[1][value] = MAX_VALUE;
			}
			for (int value = 0; value < it; value++) {
				long long cost = res[0][value];
				if (cost == MAX_VALUE)
					continue;
				if (value < it - 1) {
					long long ncost = cost + all[value + 1] - all[value];
					if (value + 1 <= id[pos])
						ncost = cost - all[value + 1] + all[value];
					if (res[0][value + 1] > ncost) {
						res[0][value + 1] = ncost;
					}
				}
				if (pos < n - 1) {
					long long ncost = cost + abs(all[id[pos + 1]] - all[value]);
					if (res[0 + 1][value] > ncost) {
						res[0 + 1][value] = ncost;
					}
				}
			}
		}
		long long best = MAX_VALUE;
		for (int i = 0; i < it; i++)
			best = min(best, res[0][i]);
		cout << best;

}