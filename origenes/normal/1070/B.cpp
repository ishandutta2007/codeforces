#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define reset(a,b) memset(a, b, sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl;
#define BUGP(x) cout << #x << " = " << x._1 << ", " << x._2 << endl;
#define pb push_back
#define _1 first
#define _2 second
#define PR(x,a,b) { cout << #x << " = "; FOR(_,a,b) cout << x[_] << ' '; cout << endl; }
#define CON(x) { cout << #x << " = "; for (auto i: x) cout << i << ' '; cout << endl; }
#define eps 1e-9
#define sqr(x) ((x) * (x))
#define all(x) x.begin(), x.end()
#define mod 1000000007

long long n, a, b, c, d, ip, x;
int trie[13300300], cnt, white[13300300], swhite[13300300], par[13300300];
char sign, nsign, cc;
vector<pair<long long, long long>> blist, wlist;
vector<long long> black;
set<pair<long long, long long>> ans;

long long getip() {
  cin >> a >> cc >> b >> cc >> c >> cc >> d;
  return a * (1 << 24) + b * (1 << 16) + c * (1 << 8) + d;
}

void putip(long long ip, long long x) {
  cout << (ip / (1 << 24)) << '.' << (ip % (1 << 24)) / (1 << 16) << '.' << (ip % (1 << 16)) / (1 << 8) << '.' << (ip % (1 << 8)) << '/' << x << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin >> n >> sign;
  REP (i, n) {
    ip = getip();
    if ((cin >> nsign) && nsign == '/') cin >> x;
    else x = 32;

    if (sign == '+') wlist.pb({ip, x});
    else blist.pb({ip, x});

    if (nsign == '/') cin >> sign;
    else sign = nsign;
  }

  for (auto p: wlist) {
    ip = p._1; x = p._2;
    long long cur = 0;
    FORD (i, 31, 32 - x) {
      long long bit = ((1LL << i) & ip) ? 1 : 0;
      if (!trie[cur + bit]) cnt += 2, trie[cur + bit] = cnt, par[cnt] = cur;
      white[cur] = 1;
      cur = trie[cur + bit];
    }
    swhite[cur] = white[cur] = 1;
  }

  for (auto p: blist) {
    ip = p._1; x = p._2;
    long long cur = 0;
    FORD (i, 31, 32 - x) {
      long long bit = ((1LL << i) & ip) ? 1 : 0;
      if (!trie[cur + bit]) cnt += 2, trie[cur + bit] = cnt, par[cnt] = cur;
      if (swhite[cur]) {
        cout << -1;
        return 0;
      }
      cur = trie[cur + bit];
    }
    black.pb(cur);
    if (white[cur]) {
      cout << -1;
      return 0;
    }
  }

  REP (i, blist.size()) {
    long long node = black[i];
    ip = blist[i]._1;
    x = blist[i]._2;

    while (node && !white[par[node]]) {
      node = par[node];
      x--;
    }

    long long mask = 0;
    REP (j, x) mask |= (1LL << (31 - j));
    ip &= mask;
    ans.insert({ip, x});
  }

  cout << ans.size() << endl;
  for (auto p: ans) {
    ip = p._1; x = p._2;
    putip(ip, x);
  }
}