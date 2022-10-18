#include <list>
#include <map>
#include <stack>
#include <set>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>
#include <functional>
#include <iomanip>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <tuple>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = (b)-1; i >= a; i--)
#define FORIT(i,c) for (auto i=(c).begin(); i!=(c).end(); i++)
#define mp make_pair
#define pb push_back
#define has(c,i) ((c).find(i) != (c).end())
#define DBG(...) ({ if(1) fprintf(stderr, __VA_ARGS__); })
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

bool even(char c) {
	return ((c-'0') % 2 == 0);
}

int main() {
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	int n = sz(s);
	FOR(i,0,n-1) {
		if (even(s[i]) && s[i] < s[n-1]) {
			cout << s.substr(0,i) << s[n-1] << s.substr(i+1,n-i-2) << s[i] << endl;
			return 0;
		}
	}
	FORD(i,0,n-1) {
		if (even(s[i])) {
			cout << s.substr(0,i) << s[n-1] << s.substr(i+1,n-i-2) << s[i] << endl;
			return 0;
		}
	}
	cout << -1 << endl;



}