#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define re return
#define pb push_back

#define all(v) (v).begin(), (v).end()

#define F(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define f(i, n) F(i, 0, n)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int run();

int main() {
#ifdef home
  freopen("i", "r", stdin);
  freopen("d", "w", stderr);
#endif // home
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  run();
}

int n;
struct Trie {
  int next[2];
  int cnt;
  Trie() {
    cnt = 0;
    next[0] = -1;
    next[1] = -1;
  };
} trie[10000000];

const int sz = 30;

int bits[sz];

int cnt = 1;

void add(int v) {
  f(i, sz) {
    bits[i] = v & 1;
    v /= 2;
  }
  int cur = 0;
  for (int i = sz - 1; i >= 0; i--) {
    if (trie[cur].next[bits[i]] == -1) {
      trie[cur].next[bits[i]] = cnt++;
    }
    cur = trie[cur].next[bits[i]];
    trie[cur].cnt++;
  }
}

int find(int v) {
  f(i, sz) {
    bits[i] = v & 1;
    v /= 2;
  }
  int cur = 0;
  int ans = 0;
  for (int i = sz - 1; i >= 0; i--) {
    if ((trie[cur].next[bits[i]] == -1) || (trie[trie[cur].next[bits[i]]].cnt == 0)) {
      cur = trie[cur].next[!bits[i]];
      ans ^= (1 << i);
    } else {
      cur = trie[cur].next[bits[i]];
    }
    trie[cur].cnt--;
  }
  re ans;
}

int a[500500];
int k[500500];

int run() {
  int n;
  cin >> n;
  f(i, n) {
    cin >> a[i];
  }
  f(i, n) {
    cin >> k[i];
    add(k[i]);
  }
  f(i, n) {
    cout << find(a[i]) << ' ';
  }
}