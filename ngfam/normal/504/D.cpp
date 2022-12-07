
#include<bits/stdc++.h>

using namespace std;

const int MAXK = 601;
const int MAXN = 2002;
const int MAXM = MAXN / 50 + 2;
const long long base = 1LL << 50;

typedef bitset<MAXN> bs;

struct Number{
  long long a[MAXM];

  Number() {
    memset(a, 0, sizeof a);
  }

  Number operator+(const Number &rhs) const{
    Number res;
    for(int i = 0; i < MAXM - 1; ++i) {
      res.a[i] += a[i] + rhs.a[i];
      res.a[i + 1] += res.a[i] / base;
      res.a[i] %= base;
    }
    return res;
  }
};

int n;
bs a[MAXN], d[MAXN];
int id[MAXN];

Number pw10[MAXK][10];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  for(int i = 0; i < 10; ++i) pw10[0][i].a[0] = i;
  for(int i = 1; i < MAXK; ++i) {
    pw10[i][1] = pw10[i - 1][9] + pw10[i - 1][1];
    for(int j = 2; j < 10; ++j) {
      pw10[i][j] = pw10[i][j - 1] + pw10[i][1];
    }
  }

  memset(id, -1, sizeof id);

  cin >> n;
  for(int i = 0; i < n; ++i) {
    string s; cin >> s;
    Number num;
    reverse(s.begin(), s.end());
    for(int i = 0; i < s.size(); ++i) {
      num = num + pw10[i][s[i] - '0'];
    }
    bs cur;
    for(int i = MAXM - 1; i >= 0; --i) {
      cur = (cur << 50) | bs(num.a[i]);
    }

    //cout << cur << endl;

    bool invalid = false;

    bs res;
    res[i] = 1;

    for(int j = MAXN - 1; j >= 0; --j) {
      if(cur[j]) {
        if(id[j] == -1) {
          id[j] = i;
          a[j] = cur;
          invalid = true;
          d[j] = res;
          break;
        }
        else {
          res ^= d[j];
          cur ^= a[j];
        }
      }
    }

    if(!invalid) {
      res[i] = 0;
      cout << res.count() << " ";
      for(int i = 0; i < MAXN; ++i) if(res[i]) cout << i << " ";
      cout << endl;
    }
    else cout << 0 << endl;
  }

  return 0;
}