#pragma GCC optimize("Ofast", "-funroll-loops", "-fdelete-null-pointer-checks")
#pragma GCC target("ssse3", "sse3", "sse2", "sse", "avx2", "avx")
#pragma GCC optimize(3, "Ofast", "inline")
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <queue>
#include <bitset>
#include <set>
#include <deque>
#include <map>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 2501;
int a[sz][sz];
pair<int, pii> pos[sz*sz];
int n;
bitset<sz> mem[sz];

inline int readInt() {
	int x = 0; char ch = getchar(); bool s = 1;
	while (ch<'0' || ch>'9') { if (ch == '-')s = 0; ch = getchar(); }
	while (ch >= '0'&&ch <= '9') { x = (x << 3) + (x << 1) + ch - '0'; ch = getchar(); }
	return s ? x : -x;
}

int main() {
	//fast;
	n = readInt();
	int tot = 0, val;
	foru(i, 0, n) {
		foru(j, 0, n) {
		    a[i][j] = readInt();
			pos[tot++] = { a[i][j],{i,j} };
		}
	}
	sort(pos, pos + n * n, greater<pair<int, pii>>());
	vector<vector<pii>> vals;
	vector<pii> cur{ pos[0].ss };
	foru(i, 1, n*n) {
		if (pos[i].ff != pos[i - 1].ff) {
			vals.pb(cur);
			cur.clear();
		}
		cur.pb(pos[i].ss);
	}
	vals.pb(cur);
	for (vector<pii> v : vals) {
		for (pii ii : v) 
			mem[ii.ff][ii.ss] = 1;
		for (pii ii : v) {
			if ((mem[ii.ff] | mem[ii.ss]).count() != n) {
				printf("NOT MAGIC\n");
				return 0;
			}
		}
	}
	foru(i,0,n){
	    if(a[i][i]!=0){
	        	printf("NOT MAGIC\n");
				return 0;
	    }
	}
	printf("MAGIC\n");
	return 0;
}