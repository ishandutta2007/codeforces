#include<iostream>
#include<cmath>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<queue>
#include<vector>
#include<functional>
#include<stack>
#include<string>
#include<map>
#include<set>
#include<iomanip>
#include<numeric>
#include<sstream>

using namespace std;
#define inf 147483640 //inte max men skitsamma
#define negInf -147483640 //inte min men skitsamma
#define rep(i, a, b) for(int i = a; i < (b); ++i) // rep(i, 0, n)
#define trav(a, x) for(auto& a : x) //iterate through all members of example vector;
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef priority_queue<int> pq;


void solve(char s[1000005], ll k, int l) {
	int n = l;

	ll c = 0;
	int start = 0;
	rep(i, 0, n) {
		if (s[i] == '1') c++;
		else {
			if (c <= k) {
				swap(s[i - c], s[i]);
				k -= c;
			}
			else {
				swap(s[i - k], s[i]);
				k = 0;
			}

		}
		if (k == 0) break;
	}
}


int main() {

	int q;
	cin >> q;

	rep(p, 0, q) {
		ll n, k;

		cin >> n >> k;



		char s[1000005];
		cin >> s;

		if (n == 1000000) {

            /*
			if (s[0] == '0' || s[0] == '1') {

			}
			assert(false);
            */
		}


		solve(s, k, n);
		cout << s << endl;
	}
}
/**/