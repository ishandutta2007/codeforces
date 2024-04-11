#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;


const int N = 3000000;
int lp[N + 1];
std::vector<int> pr;
std::set<int> op;
void sieve() {
	for (int i = 2; i <= N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back(i);
			op.insert(i);
		}
		for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
			lp[i * pr[j]] = pr[j];
	}
}

bool isPrime(int n) {
	return (op.find(n) != op.end()); 
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	sieve();
	int n; cin >> n;
	vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; }
	int y = 0;
	int u = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] == 1) {
			u++;
		} 
	}
	if (u >= 2) {
		for (int i = 0; i < n; ++i) {
			if (a[i] != 1 && isPrime(a[i] + 1))
			{
				cout << u + 1 << "\n";
				for (int i = 0; i < u; ++i) cout << 1 << " ";
				cout << a[i];
				return 0;
			} 
		}	
		cout << u << "\n";
		for (int i = 0; i < u; ++i) cout << 1 << " ";
		return 0;
	} else if(n == 1) {
		cout << 1 << "\n";
		cout << a[0];
	} else {
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (isPrime(a[i] + a[j])) {
					cout << 2 << "\n" << a[i] << " " << a[j];
					return 0;
				} 
			}
		}
		cout << 1 << "\n" << a[0];
	}
}