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

int N;
int num[100000][2];

int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)cin >> num[i][0] >> num[i][1];
	for (int i = 0; i < N; i++) {
		if (num[i][0] != num[i][1]) {
			cout << "rated\n";
			return 0;
		}
	}
	for (int i = 0; i < N - 1; i++) {
		if (num[i][0] < num[i + 1][0]) {
			cout << "unrated\n";
			return 0;
		}
	}
	cout << "maybe\n";
	return 0;
}