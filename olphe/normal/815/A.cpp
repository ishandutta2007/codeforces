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
list<long long int> Prime(int M) {
	list<long long int>P;
	P.push_back(2);
	P.push_back(3);
	for (int i = 5; i <= M; i += 6) {
		bool flag = true;
		for (auto j : P) {
			if (i%j == 0) {
				flag = false;
				break;
			}
		}
		if (flag)P.push_back(i);
		flag = true;
		for (auto j : P) {
			if ((i + 2) % j == 0) {
				flag = false;
				break;
			}
		}
		if (flag)P.push_back(i + 2);
	}
	return P;
}

long long int N, M, K, Q, W, H;
long long int ans;

int main() {
	ios::sync_with_stdio(false);
	cin >> H >> W;
	int num[101][101] = {};
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			cin >> num[i][j];
		}
	}
	int nu = 0;
	ans = 100000;
	int bag = 1000;
	for (int i = 1; i <= W; i++)bag = min(bag, num[1][i]);
	//cout << bag << endl;
	for (int i = 0; i <= bag; i++) {
		int box[101][101] = {};
		for (int j = 1; j <= H; j++) {
			for (int k = 1; k <= W; k++)box[j][k] = num[j][k];
		}
		for (int j = 1; j <= W; j++)box[1][j] -= i;
		int add = 0;
		for (int j = 1; j <= W; j++) {
			int mi = 1000;
			for (int k = 1; k <= H; k++)mi = min(mi, box[k][j]);
			add += mi;
			for (int k = 1; k <= H; k++)box[k][j] -= mi;
		}
		for (int j = 2; j <= H; j++) {
			int mi = 1000;
			for (int k = 1; k <= W; k++)mi = min(mi, box[j][k]);
			add += mi;
			for (int k = 1; k <= W; k++)box[j][k] -= mi;
		}
		bool flag = true;
		for (int j = 1; j <= H; j++) {
			for (int k = 1; k <= W; k++) {
				if (box[j][k] != 0) {
					flag = false;
					break;
				}
			}
			if (!flag)break;
		}
		//cout << ans << " " << i+add << endl;
		if (flag) {
			if (ans > i + add) {
				ans = i + add;
				nu = i;
			}
		}
	}
	if (ans == 100000)cout << "-1\n";
	else {
		cout << ans << endl;
		int box[101][101] = {};
		for (int j = 1; j <= H; j++) {
			for (int k = 1; k <= W; k++)box[j][k] = num[j][k];
		}
		for (int j = 1; j <= W; j++)box[1][j] -= nu;
		for (int j = 0; j < nu; j++)cout << "row 1\n";
		int add = 0;
		for (int j = 1; j <= W; j++) {
			int mi = 1000;
			for (int k = 1; k <= H; k++)mi = min(mi, box[k][j]);
			add += mi;
			for (int k = 1; k <= H; k++)box[k][j] -= mi;
			for (int k = 0; k < mi; k++)cout << "col " << j << endl;
		}
		for (int j = 2; j <= H; j++) {
			int mi = 1000;
			for (int k = 1; k <= W; k++)mi = min(mi, box[j][k]);
			add += mi;
			for (int k = 1; k <= W; k++)box[j][k] -= mi;
			for (int k = 0; k < mi; k++)cout << "row " << j << endl;
		}
		bool flag = true;
		for (int j = 1; j <= H; j++) {
			for (int k = 1; k <= W; k++) {
				if (box[j][k] != 0) {
					flag = false;
					break;
				}
			}
			if (!flag)break;
		}
	}
	return 0;
}