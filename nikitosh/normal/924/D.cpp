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

const int MAX_N = 5.2e5;

int opened[3], t[2][MAX_N * 2]; 

struct Event {
  	int p, q;
  	int open;
  	int type;
  	int p2, q2;
  	Event(int _p, int _q, int _open, int _type, int _p2, int _q2): p(_p), q(_q), open(_open), type(_type), p2(_p2), q2(_q2) {}
  	bool operator<(const Event &e) {
  	 	ll a = e.p * 1ll * q, b = p * 1ll * e.q;
  	 	if (a != b)
  	 		return a > b;
  	 	if (open != e.open)
  	 		return open < e.open;
  	 	a = e.p2 * 1ll * q2, b = p2 * 1ll * e.q2;
  	 	return a < b;
  	}
};

vector<Event> events;
map<pii, int> m;

void update(int type, int ind) {
 	while (ind > 0)
 		t[type][ind] += 1, ind /= 2;
}

int get(int type, int l, int r) {
    int res = 0;
    while (l <= r && l > 0) {
     	if (l % 2 == 1)
			res += t[type][l], l++;     		
     	if (r % 2 == 0)
			res += t[type][r], r--;
		l /= 2, r /= 2;			     		
    }
    return res;
}	

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n, w;
	scanf("%d%d", &n, &w);
	forn (i, n) {
		int x, v, type;
		scanf("%d%d", &x, &v);
		if (x < 0)
			type = 0;
		else
			type = 1;
		int p1 = abs(x), q1 = abs(v) + w, p2 = abs(x), q2 = abs(v) - w;
		int g1 = __gcd(p1, q1);
		p1 /= g1, q1 /= g1;
		int g2 = __gcd(p2, q2);
		p2 /= g2, q2 /= g2;
		//printf("%d %d %d %d\n", p1, q1, p2, q2);
		events.pb(Event(p1, q1, -1, type, p2, q2));
		events.pb(Event(p2, q2, 1, type, p1, q1));
	}
	if (w == 0) {
	 	for (auto &ev : events) {
	 	 	if (ev.open == -1)
	 	 		m[mp(ev.p, ev.q)]++;
	 	}
	 	ll ans = 0;
		for (auto &np : m)
			ans += np.sc * 1ll * (np.sc - 1) / 2;
		printf(I64, ans);
		return 0;
	}
	int tSize = 1;
	while (tSize < sz(events))
		tSize *= 2;

	sort(all(events));
	ll ans = 0;
	int curIndex = 0;
	for (auto &ev : events) {
		//printf("%d %d %d %d\n", ev.p, ev.q, ev.open, ev.type);
		if (!m.count(mp(ev.p, ev.q))) {
		 	m[mp(ev.p, ev.q)] = curIndex++;
		}
		if (ev.open == -1) {
			opened[ev.type]++;
        	ans += opened[ev.type ^ 1];
        	//printf("%d\n", opened[ev.type ^ 1]);
		}
		else {        
        	opened[ev.type]--;
        	int ind1 = m[mp(ev.p2, ev.q2)], ind2 = m[mp(ev.p, ev.q)];
        	ans += get(ev.type, ind1 + tSize, ind2 + tSize);
        	update(ev.type, ind1 + tSize);
	 	}
	}
	printf(I64, ans);
	return 0;
}