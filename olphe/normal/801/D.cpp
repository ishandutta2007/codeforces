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

long long int N;
long double x[1000], y[1000];
long double dis[1000][1000];
long double ans = 100000000000;

int main(){
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j)continue;
			if (i > j)dis[i][j] = dis[j][i];
			else dis[i][j] = sqrt(pow(y[j] - y[i], 2) + pow(x[j] - x[i], 2));
			ans = min(ans, dis[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		long double a = dis[i][(i + 1) % N];
		long double b = dis[(i + 1) % N][(i + N - 1) % N];
		long double c = dis[(i + N - 1) % N][i];
		long double s = (a + b + c) / 2;
		long double T = sqrt(s*(s - a)*(s - b)*(s - c));
		ans = min(T / b, ans);
	}
	cout << setprecision(15) << ans << endl;
}