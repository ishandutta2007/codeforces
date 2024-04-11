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

int a,b;
char ward[2000][501];
int num;
bool flag;

int main() {
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		cin >> ward[i];
	}
	for (int i = 0; i < b; i++) {
		cin >> ward[i + a];
		for (int j = 0; j < a; j++) {
			flag = true;
			if (ward[i + a][0] != ward[j][0]) {
				flag = false;
			}
			if (flag) {
				for (int k = 0; ward[i + a][k] != NULL; k++) {
					if ((ward[i + a][k + 1] != ward[j][k + 1]) || (ward[i + a][k + 1] == NULL&&ward[j][k+1] != NULL)) {
						flag = false;
						break;
					}
				}
			}
			if (flag) {
				num++;
				break;
			}
		}
	}
	//cout << num;
	if (num % 2) {
		if (a + 1 > b) {
			cout << "YES\n";
		}
		else cout << "NO\n";
	}
	else {
		if (a > b)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}