#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORN(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define BUG(x) cerr << #x << " = " << x << endl
#define SIZE(a) ((int) a.size())

#define PI acos(-1)

#define maxn 111  

typedef pair<int, int> pii;
typedef vector<int> vi;
vector<vi> rounds;

int n, a[111];

void solve() {
  

  

  while (true) {
    vector<pii> p;
    FOR (i, 0, n - 1) p.push_back(make_pair(a[i], i));
    sort(p.begin(), p.end());


    if (p[0].first == p[n - 1].first) {
      return;
    }

    vector<int> round;

    FORD (i, n - 1, n - 2)
      if (p[i].first != p[0].first) round.push_back(p[i].second);
      else break;

    if (SIZE(round) == 1) {
      int last = round[0];
      int ok = -1;

      REP(i, SIZE(rounds)) {
        if (rounds[i][last] == 0) {
          ok = 1;
          int cnt = 0;
          REP(j, n) 
            cnt += rounds[i][j];

          if (cnt < 5) {
            rounds[i][last] = 1;
          }
          else {
            vector<int> newRound(n, 0);
            cnt = 0;
            REP(j, n) {
              cnt += rounds[i][j];

              if (rounds[i][j] == 1 && cnt > 2) {
                rounds[i][j] = 0;
                newRound[j] = 1;
              }
            }

            newRound[last] = 1;
            rounds.push_back(newRound);
          }

          a[last] = max(a[last] - 1, 0);
          break;
        }
      }

      if (ok == -1) {
        vector<int> newRound(n, 0);
        newRound[last] = 1;
        a[last] = max(a[last] - 1, 0);

        int other = last - 1;
        if (other < 0) other = last + 1;
        newRound[other] = 1;
        a[other] = max(a[other] - 1, 0);

        rounds.push_back(newRound);
      }
    }
    else {
      vector<int> newRound(n, 0);

      REP(i, SIZE(round)) {
        newRound[round[i]] = 1;
        a[round[i]] = max(a[round[i]] - 1, 0);
      }

      rounds.push_back(newRound);
    }
  }


}

int main() {
  //just to test
  scanf("%d", &n);
  REP(i, n)
    scanf("%d", a + i);

  solve();

  cout << a[0] << endl;
  cout << SIZE(rounds) << endl;
  REP(i, SIZE(rounds)) {
    REP(j, SIZE(rounds[i])) cout << rounds[i][j];
    cout << endl;
  }
  
  return 0;
}