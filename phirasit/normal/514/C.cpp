#include <iostream>
#include <set>

using namespace std;

const int N = 600010;
const long long mod = 1000000009ll; 
const long long a = 101ll;
const long long b = 103ll;

typedef pair<int, long long> pil;
set<pil> S, S2;

long long pw[N], pw2[N];
int n, m;

int main() {

	ios::sync_with_stdio(false);

	pw[0] = pw2[0] = 1ll;
	for(int i = 1;i < N;i++) {
		pw[i] = (a * pw[i-1]) % mod;
		pw2[i] = (b * pw2[i-1]) % mod;
	}

	cin >> n >> m;
	for(int i = 0;i < n;i++) {
		string str;
		cin >> str;
		long long val = 0ll, val2 = 0ll;
		for(char ch : str) {
			val = (a * val + (ch - 'a')) % mod;
			val2 = (b * val2 + (ch - 'a')) % mod;
		}
		S.insert(pil(str.length(), val));
		S2.insert(pil(str.length(), val2));
	}

	for(int i = 0;i < m;i++) {
		string str;
		cin >> str;
		bool found = false;
		long long val = 0ll, val2 = 0ll;
		for(char ch : str) {
			val = (a * val + (ch - 'a')) % mod;
			val2 = (b * val2 + (ch - 'a')) % mod;
		}
		int l = str.length();
		for(int i = 0;i < l and !found;i++) {
			for(int j = 0;j < 3;j++) {
				if(j == str[i]-'a') continue;
				long long nw = (val + (j - (str[i]-'a')) * pw[l-i-1]) % mod;
				nw = (nw + mod) % mod;
				long long nw2 = (val2 + (j - (str[i]-'a')) * pw2[l-i-1]) % mod;
				nw2 = (nw2 + mod) % mod;
				if(S.find(pil(l, nw)) != S.end() and S2.find(pil(l, nw2)) != S2.end()) {
					found = true;
				}
			}
		}
		cout << (found ? "YES" : "NO") << "\n";
	}
	return 0;
}