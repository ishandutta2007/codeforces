#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

struct Path {
	long long to;
	long long no;
	long long w;
};

long long N;
vector <Path> Map[100100];
long long A[100100];
long long W[100100];

long long ConstructTree (long long x, long long f) {
	long long Sum = 0;
	for (long long i = 0; i < Map[x].size(); i++) {
		if (Map[x][i].to == f) continue;
		A[Map[x][i].no] = ConstructTree (Map[x][i].to, x);
		Sum += A[Map[x][i].no];
	}
	Sum++;
	return Sum;
}

int main () {
	cin >> N;
	for (long long i = 1; i < N; i++) {
		long long f, t, w;
		cin >> f >> t >> w;
		Map[f].push_back ((Path){t, i, w});
		Map[t].push_back ((Path){f, i, w});
		W[i] = w;
	}
	ConstructTree (1, 0);
	double Ans = 0;
	for (long long i = 1; i < N; i++)
		Ans += (double)W[i] * ((double)(6.0 * A[i] * (N - A[i]))) / ((double)N * (N - 1));
	long long Q = 0;
	cin >> Q;
	for (long long i = 1; i <= Q; i++) {
		long long Ci, Cw;
		cin >> Ci >> Cw;
		Ans -= (double)W[Ci] * ((double)(6.0 * A[Ci] * (N - A[Ci]))) / ((double)N * (N - 1));
		Ans += (double)Cw * ((double)(6.0 * A[Ci] * (N - A[Ci]))) / ((double)N * (N - 1));
		W[Ci] = Cw;
		printf ("%.10lf\n", Ans);
	}
	return 0;
}