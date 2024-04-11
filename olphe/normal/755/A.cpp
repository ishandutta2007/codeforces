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

int N;

int main() {
	cin >> N;
	if(N+2<1000)	cout << N + 2 << endl;
	else cout << N - 2 << endl;
	return 0;
}