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

long long int H, W;
string s;
string field[1002];
int dp[1002][1002] = {};
int sx, sy, gx, gy;
queue<int>Q;

int main() {
	cin >> H >> W;
	for (int i = 1; i <= H; i++) {
		field[i].push_back('*');
		cin >> s;
		field[i] += s;
		field[i].push_back('*');
	}
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			dp[i][j] = INT_MAX;
			if (field[i][j] == 'S') {
				sx = j;
				sy = i;
				dp[i][j] = 0;
			}
			if (field[i][j] == 'T') {
				gx = j;
				gy = i;
			}
		}
	}
	for (int i = sy; i > 0; i--) {
		if (field[i][sx] == '*')break;
		dp[i][sx] = 0;
		Q.push(i * 2000 + sx);
	}
	for (int i = sy; i <= H; i++) {
		if (field[i][sx] == '*')break;
		dp[i][sx] = 0;
		Q.push(i * 2000 + sx);
	}
	for (int i = sx; i > 0; i--) {
		if (field[sy][i] == '*')break;
		dp[sy][i] = 0;
		Q.push(sy * 2000 + i);
	}
	for (int i = sx; i <= W; i++) {
		if (field[sy][i] == '*')break;
		dp[sy][i] = 0;
		Q.push(sy * 2000 + i);
	}
	while (!Q.empty()) {
		int c = Q.front();
		int cx = c % 2000;
		int cy = c / 2000;
		for (int i = cy; i > 0; i--) {
			if (field[i][cx] == '*')break;
			if (dp[i][cx] > dp[cy][cx] + 1) {
				dp[i][cx] = dp[cy][cx] + 1;
				if (i == gy&&cx == gx)break;
			}
		}
		for (int i = cy; i <= H; i++) {
			if (field[i][cx] == '*')break;
			if (dp[i][cx] > dp[cy][cx] + 1) {
				dp[i][cx] = dp[cy][cx] + 1;
				if (i == gy&&cx == gx)break;
			}
		}
		for (int i = cx; i > 0; i--) {
			if (field[cy][i] == '*')break;
			if (dp[cy][i] > dp[cy][cx] + 1) {
				dp[cy][i] = dp[cy][cx] + 1;
				if (i == gx&&cy == gy)break;
			}
		}
		for (int i = cx; i <= W; i++) {
			if (field[cy][i] == '*')break;
			if (dp[cy][i] > dp[cy][cx] + 1) {
				dp[cy][i] = dp[cy][cx] + 1;
				if (i == gx&&cy == gy)break;
			}
		}
		Q.pop();
	}
	for (int i = gy; i > 0; i--) {
		if (field[i][gx] == '*')break;
		if (dp[i][gx] < 2) {
			cout << "YES\n";
			return 0;
		}
	}
	for (int i = gy; i <= H; i++) {
		if (field[i][gx] == '*')break;
		if (dp[i][gx] < 2) {
			cout << "YES\n";
			return 0;
		}
	}
	for (int i = gx; i > 0; i--) {
		if (field[gy][i] == '*')break;
		if (dp[gy][i] < 2) {
			cout << "YES\n";
			return 0;
		}
	}
	for (int i = gx; i <= W; i++) {
		if (field[gy][i] == '*')break;
		if (dp[gy][i] < 2) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}