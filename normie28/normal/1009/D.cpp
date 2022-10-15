#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 2e5;
vector < pair<int, int> > v;
int phi[MAXN], cnt, primes[MAXN];
inline int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
 
int main() {
	int n, m; cin>>n>>m;
	long long s = 0;
	for (int i = 2; i <= n; i++) {
		if (!phi[i]) { primes[cnt++] = i; phi[i] = i - 1; }
		s += phi[i];
		for (int j = 0; j < cnt; j++) {
			int k = primes[j] * i;
			if (n < k) break;
			if (i % primes[j]) phi[k] = phi[i] * phi[primes[j]];
			else { phi[k] = phi[i] * primes[j]; break; }
		}
	}
	if (m + 1 < n || s < m) { cout<<"Impossible"; return 0; }
	cout<<"Possible";
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++)
			if (gcd(i, j) == 1) {
				v.push_back(make_pair(i, j));
				if (m == (signed)v.size()) break;
			}
		if (m == (signed)v.size()) break;
	}
	cout<<endl;
	for (int i = 0; i < m; i++) cout<<v.at(i).first<<' '<<v.at(i).second<<endl;
}