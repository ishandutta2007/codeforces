#include <iostream>
#include <vector>
const int lim = 1e6;
//#include <string>
using namespace std;

vector<int> ans;

int rev(int n) {
	int rtn = 0;
	while (n > 0)
		rtn = rtn * 10 + n % 10, n /= 10;
	return rtn;
}

void preprocess() {
	bool sieve[lim + 1];
	for (int i = 0; i < lim + 1; i++) sieve[i] = true;
	vector<int> primes;
	int i;
	for (i = 2; i * i < lim; i++)
		if (sieve[i]) {
			primes.push_back(i);
			for (int j = i * i; j < lim; j += i)
				sieve[j] = false;
		}
	for (; i < lim; i++) if (sieve[i]) primes.push_back(i);
	for (i = 0; i < primes.size(); i++) {
		int r = rev(primes[i]);
		if (r <= lim && r != primes[i] && sieve[r])
			ans.push_back(primes[i]);
	}
}

int main() {
	ios::sync_with_stdio(0);
	preprocess();
	int n; cin >> n, cout << ans[n - 1] << endl;


	/*
	string s = "qd ucyhf yi q fhycu dkcruh mxeiu huluhiu yi q tyvvuhudj fhycu dkcruh. oekh jqia yi je vydt jxu djx ucyhf.";
	for (int i = 0; i < s.size(); i++) {
		s[i] -= 16;
		if (s[i] < 'a') s[i] += 26;
		cout << s[i];
	}
	*/
}