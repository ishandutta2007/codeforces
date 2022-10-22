#include "iostream"
#include "iomanip"
#include "math.h"
#include "algorithm"

using namespace std;
int N;
int num[101];
bool flag[101];
int look;
int ans;
int dis[101][101] = {};

int gcd(int a, int b) {
	int box=b;
	while (box != 0) {
		b = a%box;
		a = box;
		box = b;
	}
	return a;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			flag[j] = true;
		}
		look = i;
		while (1) {
			if (flag[num[look]]) {
				dis[i][num[look]] = dis[i][look] + 1;
				look = num[look];
				flag[look] = false;
			}
			else {
				cout << "-1\n";
				return 0;
			}
			if (look == i) {
				break;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (dis[i][j] * 2 == dis[i][i]) {
				if (dis[j][i] == dis[i][j]) {
					dis[i][i] /= 2;
					dis[j][j] /= 2;
				}
			}
		}
	}
	ans = 1;
	for (int i = 1; i <= N; i++) {
		ans = ans/gcd(dis[i][i],ans)*dis[i][i];
	}
	cout << ans << "\n";
	return 0;
}