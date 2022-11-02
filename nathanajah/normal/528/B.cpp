#include <bits/stdc++.h>
using namespace std;

vector <int> possible_sums;
pair <int,int> haha[200005];
int n;

int bit[200005];

int getlessequal(int x) {
  int tmp = upper_bound(possible_sums.begin(), possible_sums.end(), x) - possible_sums.begin();
  return tmp - 1;
}

void upd(int x, int y) {
  ++x;
  while (x < 200005) {
    bit[x] = max(bit[x], y);
    x += (x & -x);
  }
}

int get(int x) {
  if (x < 0) return 0;
  ++x;
  int res = -1;
  while (x > 0) {
    res = max(res, bit[x]);
    x -= (x & -x);
  }
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &haha[i].first, &haha[i].second);
    possible_sums.push_back(haha[i].first + haha[i].second);
  }
  sort(possible_sums.begin(), possible_sums.end());
  possible_sums.erase(unique(possible_sums.begin(),possible_sums.end()),possible_sums.end());
  sort(haha, haha + n);
  int maxi = 0;
  for (int i = 0; i < n; i++) {
    int tmp = haha[i].first - haha[i].second;
    int ind = getlessequal(tmp);

    int res = get(ind) + 1;
    upd(getlessequal(haha[i].first + haha[i].second), res);
    maxi = max(maxi, res);
  }
  printf("%d\n", maxi);
}