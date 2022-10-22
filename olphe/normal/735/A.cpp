#include "iostream"
#include "math.h"
#include "algorithm"
using namespace std;

int N, J;
char cell[100000];
bool flag[100000];
int s, g;
bool ans=1;

int main() {
	cin >> N >> J;
	cin >> cell;
	for (int i = 0; cell[i] != NULL; i++) {
		if (cell[i] != '#')flag[i] = true;
		if (cell[i] == 'G')s = i;
		if (cell[i] == 'T')g = i;
	}
	if (abs(g - s) % J == 0) {
		for (int i = s; i != g; i += (g - s)/abs(g-s) * J) {
			if (!flag[i]) {
				ans = 0;
				break;
			}
		}
	}
	else ans = 0;
	if (ans)cout << "YES\n";
	else cout << "NO\n";
	return 0;
}