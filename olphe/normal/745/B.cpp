#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "set"
#include "functional"
#include "algorithm"
#include "math.h"
using namespace std;

int H, W;
char piece[500][501];
int lx = 1000;
int ty = 1000;
int rx = -1;
int by = -1;

int main() {
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		cin >> piece[i];
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (piece[i][j] == 'X') {
				if (lx > j)lx = j;
				if (rx < j)rx = j;
				if (ty > i)ty = i;
				if (by < i)by = i;
			}
		}
	}
	for (int i = ty; i <= by; i++) {
		for (int j = lx; j <= rx; j++) {
			if (piece[i][j] == '.') {
				cout << "NO\n";
				return 0;
			}
		}
	}
	cout << "YES\n";
	return 0;
}