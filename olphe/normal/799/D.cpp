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

long long int a, b, h, w, n;
set<long long int>com;
map<long long int, int>M;
vector<long long int>ord;
int ans = 50;

void Search(long long int f, long long int s, int fnum, int snum, int deep) {
	if (fnum + snum >= ans)return;
	//	cout << f << " " << s << endl;
	if (a <= h*f&&b <= w*s) {
		ans = min(ans, fnum + snum);
		return;
	}
	if (a <= h*s&&b <= w*f) {
		ans = min(ans, fnum + snum);
		return;
	}
	if (a <= w*f&&b <= h*s) {
		ans = min(ans, fnum + snum);
		return;
	}
	if (a <= w*s&&b <= h*f) {
		ans = min(ans, fnum + snum);
		return;
	}
	if (deep == com.size())return;
	//	cout << "hijiki";
	for (int i = 0; i <= M[ord[deep]]; i++) {
		for (int j = 0; i + j <= M[ord[deep]]; j++) {
			if (((LLONG_MAX / pow(ord[deep], i - 1) + 1 >= ord[deep] * f)&&i) || !i) {
				if (((LLONG_MAX / pow(ord[deep], j - 1) + 1 >= ord[deep] * s)&&j) || !j) {
					Search(f*(long long int)pow(ord[deep], i), s*(long long int)pow(ord[deep], j), fnum + i, snum + j, deep + 1);
				}
			}
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> a >> b >> h >> w >> n;
	vector<long long int>by(n);
	for (int i = 0; i < n; i++)cin >> by[i];
	if (max(a, b) <= max(h, w) && min(a, b) <= min(h, w)) {
		cout << "0\n";
		return 0;
	}
	stable_sort(by.begin(), by.end());
	reverse(by.begin(), by.end());
	vector<long long int>imp(min(34,(int)n));
	long long int box = 1;
	int num = 0;
	for (int i = 0; i < min(34, (int)n); i++)imp[i] = by[i];
	for (auto i : imp) {
		com.insert(i);
		M[i]++;
	}
	for (auto i = com.rbegin(); i != com.rend(); ++i) {
		ord.push_back(*i);
	}
//	cout << com.size() << endl;
	Search(1, 1, 0, 0, 0);
	if (ans == 50)cout << "-1\n";
	else cout << ans << endl;
	return 0;
}