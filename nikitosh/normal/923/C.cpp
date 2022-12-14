#include <bits/stdc++.h> 

using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define fst first
#define snd second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; (i) < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; (i) >= 0; --i)
#define forab(i, a, b) for (int i = (a); (i) < (b); ++i)
#define forba(i, a, b) for (int i = (b) - 1; (i) >= (a); --i)
#define forit(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end() 

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif

#ifdef _WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define FNAME ""

const int MAX_N = 3e5 * 30 * 2.1, MAX_K = (3e5 + 10) * 2;

struct Node {
 	int nxt[2], sum;
 	Node() {
 	 	forn (i, 2)
 	 		nxt[i] = -1;
 	 	sum = 0;
 	}
};

Node nodes[MAX_N];
int currentNode = 1;
vi v;
int a[MAX_K], p[MAX_K]; 

void add(const vi &v) {
 	int cur = 0;
 	forn (i, 30) {
		nodes[cur].sum++;
		if (nodes[cur].nxt[v[i]] == -1) {
			nodes[cur].nxt[v[i]] = currentNode++;
 	 	}
 	 	cur = nodes[cur].nxt[v[i]];
 	}
 	nodes[cur].sum++;
}

int go(const vi &v) {
 	int cur = 0;
 	int ans = 0;
 	forn (i, 30) {
 		nodes[cur].sum--;
 	 	int ind = nodes[cur].nxt[v[i]], curNext = -1;
 	 	if (ind != -1 && nodes[ind].sum > 0)
 	 		curNext = ind, ans = ans * 2;
 	 	else
 	 		curNext = nodes[cur].nxt[v[i] ^ 1], ans = ans * 2 + 1;
 	 	assert(curNext != -1);
 	 	cur = curNext;
 	}
 	nodes[cur].sum--;
 	return ans;
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n;
	scanf("%d", &n);
	forn (i, n)
		scanf("%d", &a[i]);	
	forn (i, n) {
		scanf("%d", &p[i]);
		v.clear();	
		forn (k, 30) {
			int l = p[i] % 2;
			p[i] /= 2;
			v.pb(l);
		}
		reverse(all(v));
		add(v);
	}
	forn (i, n) {
	 	v.clear();	
		forn (k, 30) {
			int l = a[i] % 2;
			a[i] /= 2;
			v.pb(l);
		}
		reverse(all(v));
		printf("%d ", go(v));
	}	

	return 0;
}