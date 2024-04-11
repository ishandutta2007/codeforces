#include <bits/stdc++.h>
#define N 250
using namespace std;

int V;
vector<int> v;
map<int, int> M;

double e = 2.7182818284590452353602874713526624977;

double deviation(double a, double b) {
	return (b - a) * (b - a);
}

int main() {
	scanf("%d", &V);
	while (V--) {
		M.clear();
		int total = 0, mx = 0;
		for (int i = 0; i < N; i++) {
			int x;
			scanf("%d", &x);
			v.push_back(x);
			total += x;
			mx = max(mx, x);
			M[x]++;
		}
		double avg = (double)total / N;
		int P = (avg + 0.5);
		double poisson = 0, uniform = 0;
		for (int i = 0; i <= mx; i++) {
			uniform += deviation(((double)M[i]/N), 1.0/(2*P+1));
		}
		double meow = -P;
		for (int i = 0; i <= mx; i++) {
			double val = pow(e, meow);
			if (meow < -50) val = 0;
			poisson += deviation(((double)M[i]/N), (double)val);
			meow += log(P);
			meow -= log(i + 1);
		}
		if (poisson < uniform) printf("%d\n", P);
		else printf("%d\n", mx/2);
	}
}