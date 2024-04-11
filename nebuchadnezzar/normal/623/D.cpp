#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-9;

int n;
vector<double> p;
vector<double> now;

double get_delta(int pos) {
	/*
 	double q = 1, w = 1;
 	for (int i = 0; i < n; ++i) {
 	 	q *= (1 - now[i]);
 	 	if (i != pos) {
 	 	 	w *= (1 - now[i]);
 	 	} else {
 	 	 	w *= (1 - now[i] * (1 - p[i]));
 	 	}
 	}
 	*/
 	//cerr << q << " " << w << endl;
	return (1 - now[pos]) / (1 - now[pos] * (1 - p[pos]));
}

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d", &n);
	

	for (int i = 0; i < n; ++i) {
	 	int num;
	 	scanf("%d", &num);

	 	p.puba(num / 100.0);
	}

	
	now.resize(n, 1);
	set<pair<double, int>> best;
	double posib = 0;	

	double ans = 0;
	int c = n + 1;
	int tc = 0;

	posib = 1;
	for (int i = 0; i < n; ++i) {
	 	now[i] *= (1 - p[i]);
	 	posib *= (1 - now[i]);
	}

	for (int i = 0; i < n; ++i) {
	 	best.insert({get_delta(i), i});
	}

	//cerr << n << " " << posib << endl;
	ans = posib * n;

	while (true) {
	 	if (tc - 1000 == 0) {
	 	 	if (clock() > 1.9 * CLOCKS_PER_SEC) {
	 	 	 	break;
	 	 	}
	 	 	tc = 0;
	 	}
	 	++tc;

	 	auto it = best.begin();

	 	best.erase(it);
	 	int pos = it -> ss;
	 	//cerr << "pos " << pos << " " << now[pos] << " " << it -> ff << endl;
	 	
	 	/*
	 	int pos = -1;
	 	double best = 1e9;
	 	for (int i = 0; i < n; ++i) {
	 		double tmp = get_delta(i);
	 	 	if (best > tmp) {
	 	 	 	best = tmp;
	 	 	 	pos = i;
	 	 	}
	 	}
	 	*/
		double prev = posib;
		//cerr << now[pos] << endl;
		posib /= (1 - now[pos]);
		
		now[pos] *= (1 - p[pos]);
	 	posib *= (1 - now[pos]);

	 	best.insert({get_delta(pos), pos});

	 	//cerr << c << " " << posib << " " << (posib - prev) << endl;

	 	ans += c * (posib - prev);

	 	++c;
	}

	printf("%.10f\n", ans);

	return 0;
}