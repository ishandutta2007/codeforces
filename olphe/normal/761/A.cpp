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
const long long int MOD =1000000007;

int N, M ;
int num[2][100];
int K;
bool flag;

int main() {
	cin >> N >> M;
	if (M == 0&&N==0) {
		cout << "NO\n";
		return 0;
	}
	if (abs(M - N) == 1 || M == N)cout << "YES\n";
	else cout << "NO\n";
	return 0;
}