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

char box[4][5] = {};
char field[8][8] = {};
int num;

int main() {
	for (int i = 0; i < 4; i++) {
		cin >> box[i];
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			field[i + 2][j + 2] = box[i][j];
		}
	}
	for (int i = 2; i < 6; i++) {
		for (int j = 2; j < 6; j++) {
			if (field[i][j] == '.') {
				num = 0;
				if (field[i - 1][j - 1] == 'x') {
					num++;
					if (field[i - 2][j - 2] == 'x')num++;
				}
				if (field[i + 1][j + 1] == 'x'){
					num++;
					if (field[i + 2][j + 2] == 'x')num++;
				}
				if (num >= 2) {
					cout << "YES\n";
					return 0;
				}
				num = 0;
				if (field[i - 1][j + 1] == 'x') {
					num++;
					if (field[i - 2][j + 2] == 'x')num++;
				}
				if (field[i + 1][j - 1] == 'x') {
					num++;
					if (field[i + 2][j - 2] == 'x')num++;
				}
				if (num >= 2) {
					cout << "YES\n";
					return 0;
				}
				num = 0;
				if (field[i - 1][j] == 'x') {
					num++;
					if (field[i - 2][j] == 'x')num++;
				}
				if (field[i + 1][j] == 'x') {
					num++;
					if (field[i + 2][j] == 'x')num++;
				}
				if (num >= 2) {
					cout << "YES\n";
					return 0;
				}
				num = 0;
				if (field[i][j + 1] == 'x') {
					num++;
					if (field[i][j + 2] == 'x')num++;
				}
				if (field[i][j - 1] == 'x') {
					num++;
					if (field[i][j - 2] == 'x')num++;
				}
				if (num >= 2) {
					cout << "YES\n";
					return 0;
				}
			}
		}
	}
	cout << "NO\n";
	return 0;
}