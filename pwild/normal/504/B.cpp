#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>
#include <iomanip>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <bitset>
#include <iterator>
using namespace std;  
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<bool> vb;
const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (auto i = begin(c); i != end(c); ++i)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define has(c,i) (c.find(i) != end(c))
#define DBGDO(X) ({if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

ll a[200005];

ll bit[200005];
int N;

void init() { memset(bit,0,sizeof(bit)); }

void add(int i, ll v) {
	for (++i; i <= N+1; i += i & -i) bit[i] += v;
}

ll getSum(int i) {
	ll res = 0;
	for (++i; i; i -= i & -i) res += bit[i];
	return res;
}

int find(ll sum) {
	int n = 0, m = 1, res = N+1;
	while (2*m <= N+1) m *= 2;
	while (m) {
		if (bit[n+m] >= sum) {
			res = n+m-1;
		} else {
			n +=m;
			sum -= bit[n];
		}
		for (m /= 2; n+m > N+1; m /= 2);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	
	memset(a,0,sizeof(a));

	cin >> N;
	FOR(k,0,2) {
		init();
		FOR(i,0,N) {
			ll cur; cin >> cur;
			a[i] += cur - getSum(cur);
			add(cur,1);
		}
	}
	FORD(i,0,N) {
		if (a[i] >= N-i) {
			a[i] -= N-i;
			if (i) a[i-1]++;
		}
	}
	FOR(i,0,N) {
		int cur = find(a[i]+1);
		add(cur,-1);
		cout << cur;
		if (i < N-1) cout << " "; else cout << endl;
	}

}