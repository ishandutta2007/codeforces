#include <iostream>

using namespace std;

int N, M, W[2000], B[2000];
int Stack[2000], STop = 0;
bool Used[2000] = {false};

int main () {
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		cin >> W[i];
	for (int i = 1; i <= M; i++)
		cin >> B[i];
	for (int i = 1; i <= M; i++)
		if (!Used[B[i]]) {
			Stack[++STop] = B[i];
			Used[B[i]] = true;
		}
	int Ans = 0;
	for (int i = 1; i <= M; i++) {
		int p = 1;
		while (Stack[p] != B[i]) p++;
		for (int j = p - 1; j >= 1; j--) {
			Ans += W[Stack[j]];
			Stack[j + 1] = Stack[j];
		}
		Stack[1] = B[i];
	}
	cout << Ans << endl;
	return 0;
}