#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 2007, MAXC = 5005;

int n;
vector<int> v;

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
	 	int num;
	 	scanf("%d", &num);
		v.puba(num);
	}

	sort(bend(v));

	vector<int> arr;
	arr.resize(MAXC);
	for (int i = 0; i < n; ++i) {
	 	for (int j = i + 1; j < n; ++j) {
	 	 	arr[v[j] - v[i]]++;
	 	}
	}
	vector<ll> pref;

	pref.resize(MAXC);

	for (int i = 1; i < MAXC; ++i) {
	 	pref[i] = pref[i - 1] + arr[i - 1];
	}
 
    long double numt = 0;

	for (int i = 0; i < MAXC; ++i) {
	 	for (int j = 0; j < i; ++j) {
	 	 	numt += (long double) pref[i - j] * arr[i] * arr[j];
	 	}
	}

	long double tott = (ll) szof(v) * (szof(v) - 1) / 2;
	tott = tott * tott * tott;

	printf("%.15f\n", (double) (numt / tott));

	return 0;
}