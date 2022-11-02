#include <bits/stdc++.h>
using namespace std;

set <int> xx;
set <int> yy;
multiset <int> cutx;
multiset <int> cuty;

long long w, h, n;
char c[5];
int ct;
int main() {
  scanf("%I64d %I64d %I64d", &w, &h, &n);
  xx.insert(0);
  xx.insert(w);
  yy.insert(0);
  yy.insert(h);
  cutx.insert(w);
  cuty.insert(h);
  while (n--) {
    scanf("%s %d", c, &ct);
    if (c[0] == 'V') {
      set <int>::iterator bef = xx.lower_bound(ct);
      long long pointb = *bef;
      --bef;
      long long pointa = *bef;
      cutx.erase(cutx.find(pointb - pointa));
      xx.insert(ct);
      cutx.insert(ct - pointa);
      cutx.insert(pointb - ct);
    } else {
      set <int>::iterator bef = yy.lower_bound(ct);
      long long pointb = *bef;
      --bef;
      long long pointa = *bef;
      cuty.erase(cuty.find(pointb - pointa));
      yy.insert(ct);
      cuty.insert(ct - pointa);
      cuty.insert(pointb - ct);
    }
    long long maxX = *(cutx.rbegin());
    long long maxY = *(cuty.rbegin());
    long long res = maxX * maxY;
    printf("%I64d\n", res);
  }
}