#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (long long i = (a); i <= (b); i++)
#define FORD(i,a,b) for (long long i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(long long)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define PR(x,a,b) {cout << #x << " = "; FOR (_,a,b) cout << x[_] << ' '; cout << endl;}
#define CON(x) {cout << #x << " = "; for(auto i:x) cout << i << ' '; cout << endl;}
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

int n, k, ans, cnt, val, nom, vst[100005];
string s;
map<string, int> d, ind;
vector<int> pal[100005];

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  while (n--) {
    cin >> s >> val;
    if (ind.count(s)) {
      int id = ind[s];
      pal[id].pb(val);
    } else {
      pal[cnt].pb(val);
      ind[s] = cnt++;
    }

  }
  // BUG(cnt);
  REP (i, cnt) sort(pal[i].begin(), pal[i].end());
  for (auto p: ind) {
    s = p._1;
    val = p._2;
    int id = ind[s];
    if (vst[id]) continue;
    bool isPal = true;
    REP (i, k / 2) if (s[i] != s[k - 1 - i]) {
      isPal = false;
      break;
    }
    if (isPal) {
      int pt = pal[id].size() - 1;
      while (pt >= 0) {
        if (pt > 0) {
          int high = pal[id][pt];
          int low = pal[id][pt - 1];
          if (high <= 0) break;
          if (low > 0) ans += high + low;
          else if (high + low > 0) {
            ans += high + low;
            nom = max(-low, nom);
          }
          else nom = max(nom, high);
        } else {
          int high = pal[id][pt];
          if (high > 0) nom = max(high, nom);
        }
        pt -= 2;
      }
      continue;
    }
    
    vst[id] = 1;
    string rev = "";
    FORD (i, k - 1, 0) rev += s[i];
    if (!ind.count(rev)) continue;
    int rid = ind[rev];
    vst[rid] = 1;
    int p1 = pal[id].size() - 1;
    int p2 = pal[rid].size() - 1;
    while (p1 >= 0 && p2 >= 0) {
      if (pal[id][p1] + pal[rid][p2] <= 0) break;
      ans += pal[id][p1] + pal[rid][p2];
      p1--;p2--;
    }
  }
  // BUG(nom);
  cout << ans + nom;
}