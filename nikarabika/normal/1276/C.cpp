//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 4e5 + 10;
int *ans[maxn];
int a[maxn];
int n;
vector<int> all;
int cnt[maxn];
int ord[maxn];

bool cmp(int i, int j) { return cnt[i] > cnt[j]; }

void create(int p, int q) {
  for (int i = 0; i < p; i++)
    ans[i] = new int[q];
  iota(ord, ord + sz(all), 0);
  sort(ord, ord + sz(all), cmp);
  int ptr = 0;
  for (int j = 0; j < q; j++)
    for (int i = 0; i < p; i++) {
      while (cnt[ord[ptr]] == 0) ptr++;
      int pos = (i + j) % q;
      ans[i][pos] = ord[ptr];
      cnt[ord[ptr]]--;
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i], all.PB(a[i]);
  sort(all(all));
  all.resize(unique(all(all)) - all.begin());
  for (int i = 0; i < n; i++) {
    a[i] = lower_bound(all(all), a[i]) - all.begin();
    cnt[a[i]]++;
  }
  int best = 0,
      bestp, bestq;
  for (int p = 1; p * p <= n; p++) {
    int ready = 0;
    for (int i = 0; i < sz(all); i++)
      ready += min(p, cnt[i]);
    int q = ready / p;
    if (q < p)
      continue;
    if (p * q > best) {
      best = p * q;
      bestp = p;
      bestq = q;
    }
  }
  int rem = best;
  for (int i = 0; i < sz(all); i++) {
    smin(cnt[i], bestp);
    if (rem >= cnt[i])
      rem -= cnt[i];
    else {
      smin(cnt[i], rem);
      rem = 0;
    }
  }
  create(bestp, bestq);
  cout << best << '\n';
  cout << bestp << ' ' << bestq << '\n';
  for (int i = 0; i < bestp; i++)
    for (int j = 0; j < bestq; j++)
      cout << all[ans[i][j]] << " \n"[j == bestq - 1];
	return 0;
}