#define FNAME ""

#undef __STRICT_ANSI__

#include <bits/stdc++.h> 

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define fst first
#define snd second
#define sz(x) (int)((x).size()) 
#define forn(i,n) for (int i = 0; (i) < (n); ++i)
#define fornr(i,n) for (int i = (int)(n) - 1; (i) >= 0; --i)
#define forab(i,a,b) for (int i = (a); (i) < (b); ++i)
#define forba(i,a,b) for (int i = (int)(b) - 1; (i) >= (a); --i)
#define forit(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(),(c).end()

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif

#ifdef _WIN32
	#define I64 "%I64d"
	#define U64 "%I64u"
#else
	#define I64 "%lld"
	#define U64 "%llu"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ld;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;

const int ALPHA = 26;
const int N = 3e5 + 100; 

string empty = "";

struct vertex {
	string* result;
	vertex* dest;
	vertex* next[ALPHA];
	vertex() {
		result = &empty;
		forn(i, ALPHA) next[i] = 0;
	}
};

map<pair<string*, string*>, bool> rem;

inline bool startsWith(string &s, string &t) {
	pair<string*, string*> ind = mp(&s, &t);
	if (rem.find(ind) != rem.end()) return rem[ind];
	if (sz(s) < sz(t)) { 
		rem[ind] = false;
		return false;
	}
	forn(i, sz(t)) if (s[i] != t[i]) {
		rem[ind] = false;
		return false;
	}
	rem[ind] = true;
	return true;
}

vertex v[N];
int root = 0, cnt = 1;
char buf[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int add = 0;
	string s, in = "";
	while (gets(buf)) {
		in += string(buf) + '\n';
	}
	string wordd = "";
	vector<string> words(0);
	for(char c : in) {
		if ('a' <= c && c <= 'z') {
			wordd += c;
		} else {
			if (wordd != "") {
				words.pb(wordd);
				wordd = "";
			}
			add++;
		}
	}
	if (wordd != "") words.pb(wordd);
	
	int res = 0;
	bool isNew = false;
	for (string& word : words) {
		isNew = false;
		// cerr << word << '\n';
		vertex *now = &v[root];
		forn(i, sz(word)) {
			// cerr << "i = " << i << '\n';
			char c = word[i] - 'a';
			res++;
			if (now->next[c]) {
				now->result = &empty;
				now = now->next[c];
				if (*now->result != "" && startsWith(word, *now->result)) {
					// cerr << "I'm here\n";
					vertex *tmp = now, *ttmp = now->dest;
					int new_i = sz(*now->result) - 1;
					if (sz(word) != sz(*now->result)) {
						forab(j, i + 1, new_i + 1) {
							// cerr << "clear " << word[j] << " " << "j = " << j << '\n';
							tmp->result = &empty;
							tmp->dest = 0;
							tmp = tmp->next[word[j] - 'a'];
						}
						ttmp->result = &empty;
						ttmp->dest = 0;
					}
					// cerr << "Done.\n";
					res++;
					i = new_i;
					now = ttmp;
					// null
				} else {
					now->result = &empty;
				}
			} else {
				now->next[c] = &v[cnt];
				if (isNew) {
					now->result = &word;
					now->dest = &v[cnt + sz(word) - i - 1];
				} else {
					now->result = &empty;
				}
				now = &v[cnt++];
				isNew = true;
			}
		}
		// cerr << "res = " <<  res << '\n';
	}
	// cerr << add << '\n';
	cout << res + add << '\n';
	return 0;
}