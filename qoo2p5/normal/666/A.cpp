#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define ld long double
#define sz(x) (ll) x.size()
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eq(a, b) abs(a - b) < EPS

#ifdef DEBUG
	#define debug(x) cerr << "\033[31m" << x << "\033[39m" << endl;
#else
	#define debug(x)
#endif

const ll INF = 1e9;
const ll LINF = 1e18;
const ld EPS = 1e-9;
const ld PI = 3.141592653589;
const ll MOD = 1e9 + 7;

#define TASKNAME ""

const int N = 10010;

int n;
string s;
bool dp[N][4];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	float tbegin = clock();
	srand(time(nullptr));

#ifdef DEBUG
	freopen("input.txt", "r", stdin);
#else
	if (TASKNAME != "") {
		freopen(TASKNAME ".in", "r", stdin);
		freopen(TASKNAME ".out", "w", stdout);
	}
#endif

  cin >> s;
  n = sz(s);
  s += "111";
  
  dp[n][2] = 1;
  
  for (int i = n; i >= 0; i--) {
    for (int len = 2; len <= 3; len++) {
      if (!dp[i][len]) {
        continue;
      }
      
      for (int nlen = 2; nlen <= 3; nlen++) {
        int ni = i - nlen;
        if (ni < 5) {
          continue;
        }
        
        if (s.substr(ni, nlen) != s.substr(i, len)) {
          dp[ni][nlen] = 1;
        }
      }
    }
  }
  
  vector<string> ans;
  for (int i = n - 1; i >= 0; i--) {
    for (int len = 2; len <= 3; len++) {
      if (dp[i][len]) {
        ans.pb(s.substr(i, len));
      }
    }
  }
  
  sort(ans.begin(), ans.end());
  ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
  cout << sz(ans) << "\n";
  for (string &t : ans) {
    cout << t << "\n";
  }

#ifdef DEBUG
	cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

	return 0;
}