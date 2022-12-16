#include <bits/stdc++.h>

int N;
int A[110000];
std::pair <int, int> op[110000];
int res[110000];

int main () {
	scanf ("%d", &N);
	for (int i = 1; i <= N; ++i) scanf ("%d", &A[i]), op[i] = std::make_pair (-A[i], i);
	std::sort (op + 1, op + N + 1);
	for (int i = 1; i <= N; ++i) {
		int u = op[i].second;
		res[u] = 1;
		{
			int v = u + A[u];
			while (v <= N) {
				if (A[v] > A[u] && res[v] == 1) { res[u] = 0; break; }
				v += A[u];
			}
		}
		{
			int v = u - A[u];
			while (v >= 1) {
				if (A[v] > A[u] && res[v] == 1) { res[u] = 0; break; }
				v -= A[u];
			}
		}
	}
	for (int i = 1; i <= N; ++i) printf ("%c", (char) res[i] + 'A');
	puts ("");
}