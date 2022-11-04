#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define re return
#define pb push_back

#define F(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define f(i, n) F(i, 0, n)

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int run();

int main() {
#ifdef home
  freopen("i", "r", stdin);
  freopen("d", "w", stderr);
#endif

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  run();
}

int n;

pair<ll, ll> s[300500];

void try_solve(ll s1, ll s2, bool rev) {
  ll cnt1 = 0;
  ll cnt2 = 0;
  int i = n - 1;
  vector<int> ans1, ans2;
  while (cnt1 < s1 && i >= 0) {
    cnt1 = s[i].first * (n - i);
    ans1.pb(s[i].se + 1);
    i--;
  }
  int j = i;
  while (cnt2 < s2 && j >= 0) {
    cnt2 = s[j].first * (i - j + 1);
    ans2.pb(s[j].se + 1);
    j--;
  }
//  cerr << cnt1 << ' ' << s1 << ' ' << cnt2 << ' ' << s2 << '\n';
  if (cnt1 >= s1 && cnt2 >= s2) {
    cout << "Yes\n";
    if (rev) {
      swap(ans1, ans2);
    }
    cout << ans1.size() << ' ' << ans2.size() << '\n';
    for (auto x : ans1) {
      cout << x << ' ';
    }
    cout << '\n';
    for (auto x : ans2) {
      cout << x << ' ';
    }
    exit(0);
  }
}

int run() {
  ll s1, s2;
  cin >> n >> s1 >> s2;
  f(i, n) {
    cin >> s[i].fi;
    s[i].se = i;
  }
  sort(s, s + n);
  try_solve(s1, s2, false);
  try_solve(s2, s1, true);
  cout << "No";
}