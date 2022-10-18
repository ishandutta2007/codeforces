#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>

using namespace std;

#define pb push_back
#define f first
#define s second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define foran(i, a, n) for (int i = (int) a; i < (int) n; ++i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define all(C) (C).begin(), (C).end()

template <typename T>
inline T sqr( T x ) {
	return x * x;
}

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;

const double EPS = 1e-9;
const int MAXN = int(1e5) + 10;

int a[MAXN];
int b[MAXN];
int res[MAXN];
int n, d;
ll x;

int prev[MAXN];
int next[MAXN];

ll getNextX() {
    x = (x * 37ll + 10007ll) % 1000000007ll;
    return x;
}

void initAB() {
    for(int i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(a[i], a[(int)getNextX() % (i + 1)]);
    }
    for(int i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(b[i], b[(int)getNextX() % (i + 1)]);
    }
}

void initQueue() {
	memset (prev, -1, sizeof prev);
	memset (next, -1, sizeof next);

	int last1 = -1;
	forn(i, n) {
		if  (b[i]) {
			prev[i] = last1;
		    if  (last1 != -1) {
		    	next[last1] = i;
		    }
		    last1 = i;
		}
	}

}

inline int up( int pos, int shift ) {
	pos += shift;
	if  (pos >= n) {
		pos = n;
	}

	return pos;
}

inline int down( int pos, int shift ) {
	pos -= shift;
	if  (pos < 0) {
		pos = -1;
	}

	return pos;
}

void output() {
	forn(i, n) {
		printf("%d\n", res[i]);
	}
	exit(0);
}

inline bool cmp( int i, int j ) {
	return a[i] > a[j];
}

set <int> alives;

void Remove( int i ) {
	alives.erase(i);

	if  (next[i] != -1) {
		prev[next[i]] = prev[i];
	}

	if  (prev[i] != -1) {
		next[prev[i]] = next[i];
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	scanf("%d%d%d", &n, &d, &x);

	initAB();

	initQueue();
/*
	forn(i, n) {
		printf("%d ", a[i]);
	}
	puts("");

	forn(i, n) {
		printf("%d ", b[i]);
	}
	puts("");
*/
	int cnt1 = 0;
	forn(i, n) {
		if  (b[i]) {
			++cnt1;
		}
	}

	int sqrtN = 1;
	while (sqrtN * sqrtN < n) ++sqrtN;

	forn(i, n) {
		res[i] = 0;
	}

	
	if  (cnt1 <= sqrtN) {
		int start = 0;
		while (start < n && !b[start]) ++start;
        
        if  (start >= n) {
        	output();
        }

		forn(shift, n) {
			for (int i = start; 0 <= i && i < n; i = next[i]) {
				res[up(i, shift)] = max(res[up(i, shift)], a[shift]);
			}
		}
			
		output();
	}
	

	memset (prev, -1, sizeof prev);
	memset (next, -1, sizeof next);
	forn(i, n) {
		next[i] = i + 1;
		prev[i] = i - 1;
	}
	next[n - 1] = -1;

	vi shifts;
	forn(i, n) {
		shifts.pb(i);
		alives.insert(i);
	}

	sort(all(shifts), cmp);

	forn(s, n) {
		int shift = shifts[s];
		
		if  (alives.empty()) {
			output();
		}

		int start = *alives.begin();
		vi to_rem;

		for (int i = start; 0 <= i && i < n; i = next[i]) {
			int id = down(i, shift);

			if  (id < 0 || !b[id]) {
				continue;
			}		

			res[i] = a[shift];
			to_rem.pb(i);  
		}

		forn(j, sz(to_rem)) {
			Remove(to_rem[j]);
		}
	}

	output();

	return 0;
}