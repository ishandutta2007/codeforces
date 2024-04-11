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

long long int N,K;
long long int box;
long long int num[4000000];

int main() {
	cin >> N >> K;
	for (long long int i = 1; i*i <= N; i++) {
		if (i*i == N) {
			num[box++] = i;
			if (box == K) {
				cout << i << endl;
				return 0;
			}
			else {
				if (box * 2 > K) {
					cout << N / num[box * 2 - 1 - K] << endl;
					return 0;
				}
				else {
					cout << "-1\n";
					return 0;
				}
			}
		}
		if (N%i == 0) {
			num[box++] = i;
		}
		if (box == K) {
			cout << i << endl;
			return 0;
		}
	}
	if (K > box * 2) {
		cout << "-1\n";
		return 0;
	}
	cout << N / num[box * 2 - K]<<endl;
	return 0;
}