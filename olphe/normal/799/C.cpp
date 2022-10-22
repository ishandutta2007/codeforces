#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "math.h"
#include "utility"
#include "string"
#include "map"
#include "unordered_map"
#include "iomanip"
#include "random"

using namespace std;
const long long int MOD = 1000000007;

long long int divide = 1000000;
long long int N,D,C;
long long int b, c;
long long int df[100001], cf[100001];
long long int ds[100001], cs[100001];
char box;

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> C >> D;
	for (int i = 0; i < N; i++) {
		cin >> b >> c >> box;
		b = b* divide*divide + c*divide + i;
		if (box == 'C') {
			if (cf[c] < b) {
				cs[c] = cf[c];
				cf[c] = b;
			}
			else if (cs[c] < b) {
				cs[c] = b;
			}
		}
		else {
			if (df[c] < b) {
				ds[c] = df[c];
				df[c] = b;
			}
			else if (ds[c] < b) {
				ds[c] = b;
			}
		}
	}
	for (int i = 1; i <= 100000; i++) {
		long long int bag[4];
		bag[0] = cf[i - 1];
		bag[1] = cf[i];
		bag[2] = cs[i - 1];
		bag[3] = cs[i];
		stable_sort(bag, bag + 4);
		cf[i] = bag[3];
		cs[i] = bag[2];

		bag[0] = df[i - 1];
		bag[1] = df[i];
		bag[2] = ds[i - 1];
		bag[3] = ds[i];
		stable_sort(bag, bag + 4);
		df[i] = bag[3];
		ds[i] = bag[2];
	}
	long long int ans = 0;
	for (int i = 1; i <= C - 1; i++) {
		if (cf[i] && cf[C - i] && cf[i] != cf[C - i]) {
			ans = max(ans, cf[i] / (divide*divide) + cf[C - i] / (divide*divide));
		}
		if (cf[i] && cs[C - i] && cf[i] != cs[C - i]) {
			ans = max(ans, cf[i] / (divide*divide) + cs[C - i] / (divide*divide));
		}
		if (cs[i] && cf[C - i] && cs[i] != cf[C - i]) {
			ans = max(ans, cs[i] / (divide*divide) + cf[C - i] / (divide*divide));
		}
	}
	for (int i = 1; i <= D - 1; i++) {
		if (df[i] && df[D - i] && df[i] != df[D - i]) {
			ans = max(ans, df[i] / (divide*divide) + df[D - i] / (divide*divide));
		}
		if (df[i] && ds[D - i] && df[i] != ds[D - i]) {
			ans = max(ans, df[i] / (divide*divide) + ds[D - i] / (divide*divide));
		}
		if (ds[i] && df[D - i] && ds[i] != df[D - i]) {
			ans = max(ans, ds[i] / (divide*divide) + df[D - i] / (divide*divide));
		}
	}
	if (cf[C] && df[D])	ans = max(cf[C]/(divide*divide) + df[D]/(divide*divide), ans);
	cout << ans << endl;
	return 0;
}