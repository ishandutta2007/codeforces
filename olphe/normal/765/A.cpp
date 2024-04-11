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
#include "map"

using namespace std;
const long long int MOD = 1000000007;

int N;
char h[4];
char place[10];
int num;

int main() {
	cin >> N;
	cin >> h;

	for (int i = 0; i < N; i++) {
		cin >> place;
		if (place[5] == h[0] && place[6] == h[1] && place[7] == h[2])num++;
	}
	if (N - num > num)cout << "contest\n";
	else cout << "home\n";
	return 0;
}