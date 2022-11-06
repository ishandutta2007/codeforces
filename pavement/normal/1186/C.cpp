#include <bits/stdc++.h>
using namespace std;
#define int long long

int U, V, P[1000005];
string A, B;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> A >> B;
	for (char c : B) V += c == '1';
	P[0] = A[0] == '1';
	for (int i = 1; i < A.size(); i++)
		P[i] = P[i - 1] + (A[i] == '1');
	for (int i = 0; i < A.size() - B.size() + 1; i++)
		if ((P[i + B.size() - 1] - (i ? P[i - 1] : 0) + V) % 2 == 0) U++;
	cout << U << '\n';
}