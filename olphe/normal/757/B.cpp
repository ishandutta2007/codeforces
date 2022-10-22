#include "iostream"
#include "stdio.h"
#include "iomanip"
#include "climits"
#include "list"
#include "queue"
#include "set"
#include "functional"
#include "algorithm"
#include "math.h"
#include "string"
#include "utility"

using namespace std;

int N;
int strong;
int num[100001];
int x[100001];
int ans=0;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> strong;
		num[strong]++;
	}
	for (int i = 2; i <= 100000; i++) {
		for (int j = i; j <= 100000; j += i) {
			x[i] += num[j];
		}
		ans = max(ans, x[i]);
	}
	if(ans)	cout << ans << endl;
	else cout << "1\n";
	return 0;
}