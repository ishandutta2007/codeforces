#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define ld long double
#define sz(x) (int) x.size()
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eq(a, b) abs(a - b) < EPS

#ifdef DEBUG
  #define debug(x) cerr << "\033[31m" << x << "\033[39m" << endl;
#else
  #define debug(x)
#endif

const int INF = 1e9;
const ll LINF = 1e18;
const ld EPS = 1e-10;
const ld PI = 3.141592653589;
const int MOD = 1e9 + 7;

#define TASKNAME ""

const int N = 1e5 + 123;

int n;
unordered_map<string, unordered_set<string>> q;
unordered_map<string, int> id;
string a[N];
int counter;
vector<int> ans[N];

struct Trie {
  map<char, Trie*> nxt;
  vector<int> els;

  Trie() {}

  void add(int id, string t) {
    Trie *cur = this;

    for (int i = 0; i < sz(t); i++) {
      if (!cur->nxt.count(t[i])) {
        cur->nxt[t[i]] = new Trie();
      }

      cur = cur->nxt[t[i]];
    }

    cur->els.pb(id);
  }
};

void solve(Trie *t) {
  if (sz(t->els) > 1) {
    ans[counter++] = t->els;
  }

  for (auto &to : t->nxt) {
    solve(to.second);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
  float tbegin = clock();
  srand(42);

#ifdef DEBUG
  freopen("input.txt", "r", stdin);
#else
  if (TASKNAME != "") {
    freopen(TASKNAME ".in", "r", stdin);
    freopen(TASKNAME ".out", "w", stdout);
  }
#endif

  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    int pos = sz(s);
    for (int j = 7; j < sz(s); j++) {
      if (s[j] == '/') {
        pos = j;
        break;
      }
    }

    string addr = s.substr(0, pos);
    string query = pos == sz(s) ? "*|" : s.substr(pos, sz(s) - pos) + "|";

    q[addr].insert(query);
    a[i] = addr;
    id[addr] = i;
  }

  Trie* t = new Trie();

  for (auto &it : q) {
    vector<string> queries;
    for (auto &el : it.second) {
      queries.pb(el);
    }

    sort(queries.begin(), queries.end());
    string s = "";
    for (auto &el : queries) {
      s += el;
    }

    t->add(id[it.first], s);
  }

  solve(t);

  cout << counter << "\n";
  for (int j = 0; j < counter; j++) {
    for (auto &i : ans[j]) {
      cout << a[i] << " ";
    }
    cout << "\n";
  }

#ifdef DEBUG
  cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

  return 0;
}