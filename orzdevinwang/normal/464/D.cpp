#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++) 
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) a.size()
#define vi vector<int>
using namespace std;
const int N = 560;
int n, k;
double f[N], pf[N], ns, iv;
int main() {
	cout.precision(12), cout << fixed;
//	n = 1e5, k = 1;
	cin >> n >> k;
	iv = 1. / k;
	f[1] = 0, pf[1] = 1;
	L(i, 1, n) {
		R(j, min(550, i), 1) {
			if(pf[j] < 1e-100) {
				pf[j] = 0.0;
				continue;
			}
			double p = iv / (j + 1), z = (k - 1) * iv + j * p;
			f[j + 1] += f[j] * p + pf[j] * j * p, pf[j + 1] += pf[j] * p;
			f[j] *= z, f[j] += pf[j] * j * iv / 2, pf[j] *= z;
		} 
	}
	L(j, 1, 550) ns += f[j];
	cout << ns * k << "\n";
	return 0;
}