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

struct SegTree {

	vi v, imax;

	int init(int p, int i, int j) {
		if (i == j) return imax[p] = i;
		int p1 = init(2*p+1,i,(i+j)/2);
		int p2 = init(2*p+2,(i+j)/2+1,j);
		return imax[p] = (v[p1] >= v[p2]) ? p1 : p2;
	}

	void init()  { 
		imax = vi(4*sz(v));
		init(0,0,sz(v)-1);
	}

	int query(int p, int i, int j, int a, int b) {
		if (j < a || i > b) return -1;
		if (i >= a && j <= b) return imax[p];
		int p1 = query(2*p+1,i,(i+j)/2,a,b);
		int p2 = query(2*p+2,(i+j)/2+1,j,a,b);
		if (p1 == -1) return p2;
		return (p2 == -1 || v[p1] >= v[p2]) ? p1 : p2;
	}
	
	int query(int a, int b) { return query(0,0,sz(v)-1,a,b); }

};



int main() {
	ios_base::sync_with_stdio(false);

	int n, m, k; cin >> n >> m >> k;
	
	vector<SegTree> seg(m);
	FOR(j,0,m) seg[j].v = vi(n);
	FOR(i,0,n) {
		FOR(j,0,m) cin >> seg[j].v[i];
	}
	FOR(j,0,m) seg[j].init();

	int best = 0;
	int a = 0, b = 0;
	vi cur(m);
	vi res(m);
	while (b < n) {
		int sum = 0;
		FOR(j,0,m) {
			cur[j] = seg[j].v[seg[j].query(a,b)];
			sum += cur[j];
		}
		//cerr << a << " " << b << " " << sum << endl;
		if (sum <= k) {
			if (best < b-a+1) {
				best = b-a+1;
				FOR(j,0,m) res[j] = cur[j];
			}
			b++;
		} else {
			a++;
			if (b < a) b++;
		}
	}
	FOR(j,0,m-1) cout << res[j] << " ";
	cout << res[m-1] << endl;

	
}