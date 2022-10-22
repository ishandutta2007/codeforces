#include "iostream"
#include "iomanip"
#include "climits"
#include "list"
#include "queue"
#include "set"
#include "functional"
#include "algorithm"
#include "math.h"
#include "utility"

using namespace std;

int N,K;
int num;
int place;
char letter[10];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num >> letter;
		if (letter[0] == 'N') {
			place -= num;
			if (place < 0) {
				cout << "NO\n";
				return 0;
			}
		}
		else if (letter[0] == 'S') {
			place += num;
			if (place > 20000) {
				cout << "NO\n";
				return 0;
			}
		}
		else {
			if (place == 0 || place == 20000) {
				cout << "NO\n";
				return 0;
			}
		}
	}
	if (place) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	return 0;
}