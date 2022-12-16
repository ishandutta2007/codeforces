#include <iostream>

using namespace std;

int N, T;
int A[100000];

int main () {
	cin >> N >> T;
	for (int i = 1; i < N; i++) cin >> A[i];
	int k = 1;
	while (k < T)
		k += A[k];
	if (k == T)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}