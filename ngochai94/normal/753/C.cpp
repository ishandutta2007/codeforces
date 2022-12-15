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

int a, b, cnt[30], bestmax, remain, cmp[6000][6000], all;
int bestS;
bool pos[10000];
string avai[10000];

int query(string s) {
  cout << s << endl;
  cout.flush();
  cin >> a >> b;
  return a * 5 + b;
}


int compare(string x, string y) {
  int u = 0;
  REP (i, 4) {
    if (x[i] == y[i]) u += 5;
    else {
      FOR (j, i + 1, 3) if (x[i] == y[j] && x[j] != y[j]) {
        u++;
        break;
      }
      FOR (j, 0, i - 1) if (x[i] == y[j] && x[j] != y[j]) {
        u++;
        break;
      }
    }
  }
  return u;
}

void f() {
  bestmax = mod;
  REP (i, all) if (pos[i]) {
    reset(cnt, 0);
    int curm = 0;
    REP (j, all) if (pos[j]) {
      curm = max(curm, ++cnt[cmp[j][i]]);
    }
    if (curm < bestmax) {
      bestmax = curm;
      bestS = i;
    }
  }//a
  int res = query(avai[bestS]);
  REP (i, all) if (pos[i]) if (cmp[i][bestS] != res) {
    pos[i] = false;
    remain--;
  }
}

set<int> ss;

int main() {
  ios::sync_with_stdio(false);
  REP (d1, 10) REP (d2, 10) REP (d3, 10) REP (d4, 10) {
    ss.clear();
    ss.insert(d1);
    ss.insert(d2);
    ss.insert(d3);
    ss.insert(d4);
    if (ss.size() != 4) continue;
    string s = "";
    s += '0' + d1;
    s += '0' + d2;
    s += '0' + d3;
    s += '0' + d4;
    avai[all] = s;
    pos[all++] = true;
    remain++;
  }
  // BUG(tmp);
  // BUG(avai[1]);
  REP (i, all) REP (j, all) cmp[i][j] = compare(avai[i], avai[j]);
  // return 0;
  while (remain != 1) {
    // BUG(remain);
    f();
    // BUG(remain);
    // REP (i, all) if (pos[i]) cout << avai[i] << ' ';
    // cout << endl;

  }
  REP (i, all) if (pos[i]) query(avai[i]);
}