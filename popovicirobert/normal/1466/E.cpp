#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;

const int MOD = (int)1e9 + 7;


int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int t;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

	cin >> t;
	while(t--) {
		int n;
		cin >> n;

		vector<ll> values(n);
		vector<int> bitFreq(60);
		for(int i = 0; i < n; i++) {
			cin >> values[i];

			for(int bit = 0; bit < 60; bit++) {
				if(values[i] & (1LL << bit)) {
					bitFreq[bit]++;
				}
			}
		}

		int answer = 0;
		for(int i = 0; i < n; i++) {
			static vector<int> freqAnd(60), freqOr(60);
			fill(freqAnd.begin(), freqAnd.end(), 0);
			fill(freqOr.begin(), freqOr.end(), 0);

			for(int bit = 0; bit < 60; bit++) {
				if(values[i] & (1LL << bit)) {
					freqAnd[bit] += bitFreq[bit];
					freqOr[bit] += n;
				}
				else {
					freqOr[bit] += bitFreq[bit];
				}
			}

			int sum = 0;
			for(int bit = 0; bit < 60; bit++) {
				sum = (sum + 1LL * freqOr[bit] * ((1LL << bit) % MOD)) % MOD;
			}
			for(int bit = 0; bit < 60; bit++) {
				answer = (answer + 1LL * sum * (((1LL << bit) % MOD) * freqAnd[bit] % MOD)) % MOD;
			}
		}
		cout << answer << "\n";
	}

    return 0;
}