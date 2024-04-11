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

using namespace std;
const long long int MOD = 1000000007;


long long int N, K;
int ans[6][3] = { 0,1,2,1,0,2,1,2,0,2,1,0,2,0,1,0,2,1};

int main() {
	cin >> N >> K;
	cout << ans[int(N % 6)][K] << endl;
	return 0;
}