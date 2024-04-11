#include <algorithm>
#include <set>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  vector<int> x(1);
  vector<int> y(1);
  vector<int> p(1);
  vector<int> r(1);
  int n;
  scanf("%d", &(x[0]));
  scanf("%d", &(y[0]));
  scanf("%d", &(p[0]));
  scanf("%d", &(r[0]));
  scanf("%d", &n);
  x.resize(n + 1);
  y.resize(n + 1);
  p.resize(n + 1);
  r.resize(n + 1);
  vector<int> m(n + 1);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &(x[i]));
    scanf("%d", &(y[i]));
    scanf("%d", &(m[i]));
    scanf("%d", &(p[i]));
    scanf("%d", &(r[i]));
    x[i] -= x[0];
    y[i] -= y[0];
  } 
  x[0] = 0;
  y[0] = 0;
  ++n;
  /*int n = 250001;
  vector<int> x(n);
  for (int i = 0; i < n; ++i) x[i] = rand() % 10000000;
  vector<int> y(n);
  for (int i = 0; i < n; ++i) y[i] = rand() % 10000000;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) p[i] = 10000000;
  vector<int> r(n);
  for (int i = 0; i < n; ++i) r[i] = 20000000;
  vector<int> m(n);
  for (int i = 0; i < n; ++i) m[i] = rand() % 10000000;*/

  vector<ll> alldist(2 * n);
  for (int i = 0; i < n; ++i) {
    alldist[2 * i] = x[i] * (ll) x[i] + y[i] * (ll) y[i];
    alldist[2 * i + 1] = r[i] * (ll) r[i];
  }
  sort(alldist.begin(), alldist.end());
  int dcnt = 0;
  for (int i = 0; i < alldist.size(); ++i) {
    if (i == 0 || alldist[i] > alldist[i - 1])
      alldist[dcnt++] = alldist[i];
  }
  vector<int> dist(n);
  for (int i = 0; i < n; ++i) {
    int left = -1;
    int right = dcnt;
    ll need = x[i] * (ll) x[i] + y[i] * (ll) y[i];
    while (right - left > 1) {
      int mid = (left + right) / 2;
      if (alldist[mid] == need) {
        dist[i] = mid;
	break;
      } else if (alldist[mid] < need) {
        left = mid; 
      } else {
        right = mid;
      }
    }
    if (right - left <= 1) {
      printf("BUG!1\n");
      return 1;
    }
    need = r[i] * (ll) r[i];
    left = -1;
    right = dcnt;
    while (right - left > 1) {
      int mid = (left + right) / 2;
      if (alldist[mid] == need) {
        r[i] = mid;
	break;
      } else if (alldist[mid] < need) {
        left = mid; 
      } else {
        right = mid;
      }
    }
    if (right - left <= 1) {
      printf("BUG!2\n");
      return 1;
    }
  }

  vector<int> allpow(2 * n);
  for (int i = 0; i < n; ++i) {
    allpow[2 * i] = p[i];
    allpow[2 * i + 1] = m[i];
  }
  sort(allpow.begin(), allpow.end());
  int pcnt = 0;
  for (int i = 0; i < allpow.size(); ++i) {
    if (i == 0 || allpow[i] > allpow[i - 1])
      allpow[pcnt++] = allpow[i];
  }
  for (int i = 0; i < n; ++i) {
    int left = -1;
    int right = pcnt;
    int need = p[i];
    while (right - left > 1) {
      int mid = (left + right) / 2;
      if (allpow[mid] == need) {
        p[i] = mid;
	break;
      } else if (allpow[mid] < need) {
        left = mid; 
      } else {
        right = mid;
      }
    }
    if (right - left <= 1) {
      printf("BUG!!\n");
      return 1;
    }
    need = m[i];
    left = -1;
    right = pcnt;
    while (right - left > 1) {
      int mid = (left + right) / 2;
      if (allpow[mid] == need) {
        m[i] = mid;
	break;
      } else if (allpow[mid] < need) {
        left = mid; 
      } else {
        right = mid;
      }
    }
    if (right - left <= 1) {
      printf("BUG!!\n");
      return 1;
    }
  }
  

  vector<set<pair<int, int> > > fenwick(dcnt);
  for (int i = 1; i < n; ++i) {
    int dcoord = dist[i];
    int pcoord = m[i];
    while (dcoord < dcnt) {
      fenwick[dcoord].insert(make_pair(pcoord, i));
      dcoord |= (dcoord + 1);
    }
  }
  vector<int> queue(n);
  int qt = 0;
  int qh = 1;
  int res = 0;
  while (qt < qh) {
    int cur = queue[qt++];
    int dbound = r[cur];
    int pbound = p[cur];
    while (dbound >= 0) {
      while (!fenwick[dbound].empty() && fenwick[dbound].begin()->first <= pbound) {
        int kill = fenwick[dbound].begin()->second;
	int dcoord = dist[kill];
	int pcoord = m[kill];
	while (dcoord < dcnt) {
	  fenwick[dcoord].erase(make_pair(pcoord, kill));
	  dcoord |= (dcoord + 1);
	}
	queue[qh++] = kill;
	++res;
      }
      dbound = (dbound & (dbound + 1)) - 1;
    }
  }
  printf("%d\n", res);
  return 0;
}