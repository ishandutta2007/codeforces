#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "set"
#include "functional"
#include "algorithm"
#include "math.h"
#include "utility"

using namespace std;
const long long int MOD = 1000000007;

int N,M;
int box;
vector<int>num;
int r, l, mid;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> box;
		num.push_back(box);
	}
	sort(num.begin(), num.end());
	for (int i = 0; i < N - 1; i++) {
		if (i < N - 2) {
			l = i + 2;
			r = N - 1;
			while (1) {
				mid = (r + l) / 2;
				if (num[mid] > num[i + 1] - num[i] && num[mid] < num[i] + num[i + 1]) {
					cout << "YES\n";
					return 0;
				}
				if (num[mid] < num[i + 1] - num[i]) {
					l = mid+1;
				}
				else {
					r = mid;
				}
				if (l == r)break;
			}
		}
		if (i > 1) {
			l = 0;
			r = i - 1;
			while (1) {
				mid = (r + l) / 2;
				if (num[mid] > num[i + 1] - num[i] && num[mid] < num[i] + num[i + 1]) {
					cout << "YES\n";
					return 0;
				}
				if (num[mid] < num[i + 1] - num[i]) {
					l = mid+1;
				}
				else {
					r = mid;
				}
				if (l == r)break;
			}
		}
	}
	cout << "NO\n";
	return 0;
}