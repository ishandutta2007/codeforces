#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "set"
#include "functional"
#include "algorithm"
#include "math.h"
using namespace std;

int N, K, A, B;
int con[2];
char ans[100001];

int main() {
	cin >> N >> K >> A >> B;
	for (int i = 0; i < N; i++) {
		if (con[0] == K) {
			con[0] = 0;
			con[1] = 1;
			ans[i] = 'B';
			B--;
			if (B < 0) {
				cout << "NO\n";
				return 0;
			}
		}
		else if (con[1] == K) {
			con[1] = 0;
			con[0] = 1;
			ans[i] = 'G';
			A--;
			if (A < 0) {
				cout << "NO\n";
				return 0;
			}
		}
		else {
			if (A > B) {
				con[0]++;
				con[1] = 0;
				ans[i] = 'G';
				A--;
				if (A < 0) {
					cout << "NO\n";
					return 0;
				}
			}
			else {
				con[1]++;
				con[0] = 0;
				ans[i] = 'B';
				B--;
				if (B < 0) {
					cout << "NO\n";
					return 0;
				}
			}
		}
	}
	ans[N] = NULL;
	cout << ans << "\n";
	return 0;
}