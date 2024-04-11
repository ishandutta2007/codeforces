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

int N, L;
long long int p[200000], a[200000], b[200000];
int want[200000];
set<long long int>box[4];

int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)cin >> p[i];
	for (int i = 0; i < N; i++)cin >> a[i];
	for (int i = 0; i < N; i++)cin >> b[i];
	for (int i = 0; i < N; i++) {
		box[a[i]].insert(p[i]);
		box[b[i]].insert(p[i]);
	}
	cin >> L;
	for (int i = 0; i < L; i++)cin >> want[i];
	for (int i = 0; i < L; i++) {
		if (!box[want[i]].empty()) {
			long long int bag = *box[want[i]].begin();
			cout << bag << " ";
			box[1].erase(bag);
			box[2].erase(bag);
			box[3].erase(bag);
		}
		else cout << "-1 ";
	}
	cout << endl;
	return 0;
}