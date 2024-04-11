#include <bits/stdc++.h>

using namespace std;
const int N = 4010;

int n;
long long  v[N], p[N], d[N];
vector <int> res;
int out[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d %d", v + i, d + i, p + i);
  }
  for (int i = 1; i <= n; i++) {
    if (p[i] >= 0) {
        res.push_back(i);
        int x = v[i];
        for (int j = i + 1; j <= n; j++) {
            if (out[j]) {
                continue;
            }
                p[j] -= x;
                x--;
                if (x == 0) {
                    break;
                }
        }
      for (int j = i + 1; j <= n; j++) {
        if (out[j] || p[j] >= 0) {
          continue;
        }
        out[j] = 1;
        for (int kk = j + 1; kk <= n; kk++) {
          p[kk] -= d[j];
        }
      }
    }
  }
  cout << res.size() << endl;
  for (int i  :res ){
    cout << i << " ";
  }
  return 0;
}