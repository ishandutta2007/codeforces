#include <iostream>
#include <algorithm>
#include <set>
#include <bitset>
#include <map>
#include <vector>
#include <list>
#include <iostream>
#include <iostream>
#include <iostream>
#include <iostream>
#include <iostream>

using namespace std;

#define FOR(i, n) for(unsigned i = 0; i < (n); ++i)
#define FORU(i, j, k) for(unsigned i = (j); i <= (k); ++i)
#define FORR(i, j, k) for(unsigned i = (j); i >= (k); --i)

long D[100][100];

int main(int, char**){
  long n, m; cin >> n >> m;
  FOR(i, n) FOR(j, n) D[i][j] = 0;
  FOR(i, m){
    long a, b, c;
    cin >> a >> b >> c;
    D[a-1][b-1] += c;
  }
  FOR(i, n) FOR(j, n){
    long r = min<long long>(D[i][j], D[j][i]);
    D[i][j] -= r;
    D[j][i] -= r;
  }

  FOR(i, n){
    long long ind = 0, outd = 0;
    FOR(j, n){
      ind += D[j][i];
      outd += D[i][j];
    }
    long bst = min<long long>(ind, outd);
    FOR(j, n){
      FOR(k, n){
        if(D[j][i] > 0 && D[i][k] > 0){
          long r = min<long long>(bst, min<long long>(D[j][i], D[i][k]));
          // cout << j << " " << i << " " << k << " " << r << " " << bst << " " << D[j][i] << " " << D[i][k] << endl;
          D[j][i] -= r;
          D[i][k] -= r;
          D[j][k] += r;
          bst -= r;
        }
      }
    }
  }

  long res = 0;
  FOR(i, n) FOR(j, n) res += D[i][j];
  cout << res << endl;
  return 0;
}