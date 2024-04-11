#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "functional"

using namespace std;

//constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	while (K--) {
		string s;
		cin >> s;
		N = s.size();
		vector<long long int>befl(N + 2);
		vector<long long int>befr(N + 2);
		vector<long long int>befd(N + 2);
		vector<long long int>befu(N + 2);
		vector<long long int>aftl(N + 2,MOD);
		vector<long long int>aftr(N + 2,-MOD);
		vector<long long int>aftd(N + 2,MOD);
		vector<long long int>aftu(N + 2,-MOD);
		long long int y = 0, x = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'W') {
				y++;
				befu[i + 1] = y;
				aftd[i]=aftu[i] = y;
				aftl[i] = aftr[i] = x;
			}
			if (s[i] == 'A') {
				x--;
				befl[i + 1] = x;
				aftr[i]=aftl[i] = x;
				aftd[i] = aftu[i] = y;
			}
			if (s[i] == 'S') {
				y--;
				befd[i + 1] = y;
				aftu[i]=aftd[i] = y;
				aftl[i] = aftr[i] = x;
			}
			if (s[i] == 'D') {
				x++;
				befr[i + 1] = x;
				aftl[i]=aftr[i] = x;
				aftd[i] = aftu[i] = y;
			}
		}
		long long int ans = MOD * MOD;
		for (int i = 1; i < N + 2; i++) {
			befl[i] = min(befl[i - 1], befl[i]);
			befd[i] = min(befd[i - 1], befd[i]);
			befu[i] = max(befu[i - 1], befu[i]);
			befr[i] = max(befr[i - 1], befr[i]);
		}
		for (int i = N; i >= 0; i--) {
			aftl[i] = min(aftl[i + 1], aftl[i]);
			aftd[i] = min(aftd[i + 1], aftd[i]);
			aftu[i] = max(aftu[i + 1], aftu[i]);
			aftr[i] = max(aftr[i + 1], aftr[i]);
		}
		y = 0;
		x = 0;
		for (int i = 0; i < N; i++) {
			//cout << i <<befl[i]<<" "<<befr[i]<< " " << aftl[i] << " " << aftr[i] << endl;
			if (i) {
				if (s[i - 1] == 'W')y++;
				if (s[i - 1] == 'A')x--;
				if (s[i - 1] == 'S')y--;
				if (s[i - 1] == 'D')x++;
			}
			ans = min(ans, (max(befu[i], aftu[i]) - min(befd[i], aftd[i])+1)*(max(befr[i], aftr[i]) - min(befl[i], aftl[i])+1));
			ans = min(ans, (max({ befu[i], aftu[i] + 1,y + 1 }) - min({ befd[i], aftd[i] + 1,y + 1 }) + 1)*(max(befr[i], aftr[i]) - min(befl[i], aftl[i]) + 1));
			ans = min(ans, (max({ befu[i], aftu[i] - 1,y - 1 }) - min({ befd[i], aftd[i] - 1,y - 1 }) + 1)*(max(befr[i], aftr[i]) - min(befl[i], aftl[i]) + 1));
			ans = min(ans, (max(befu[i], aftu[i]) - min(befd[i], aftd[i]) + 1)*(max({ befr[i], aftr[i] + 1,x + 1 }) - min({ befl[i], aftl[i] + 1,x + 1 }) + 1));
			ans = min(ans, (max(befu[i], aftu[i]) - min(befd[i], aftd[i]) + 1)*(max({ befr[i], aftr[i] - 1,x - 1 }) - min({ befl[i], aftl[i] - 1,x - 1 }) + 1));
		}
		cout << ans << endl;
	}
}