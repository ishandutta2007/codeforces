#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[10005];
int dp[405][405][55];
set <pair<int,int> > posi[55];
set <pair<int,int> > nega[55];
int sum[10005];

int getsum(int l, int r) {
  if (l == 0) {
    return sum[r];
  }
  return sum[r] - sum[l-1];
}

void insertNega(int x, int y, int k) {
  set<pair<int,int> >::iterator it = nega[k].lower_bound(make_pair(x, -1000000000));
  set<pair<int,int> >::iterator it2 = nega[k].end();
  if (it != nega[k].end() && it->first == x && it->second < y) {
    nega[k].erase(it);
  }
  nega[k].insert(make_pair(x,y));
  it = nega[k].find(make_pair(x,y));
  it2 = it;
  it2++;
  if (it2 != nega[k].end() && it2->second >= it->second) {
    nega[k].erase(it);
    return;
  }
  if (it != nega[k].begin()) {
    it2 = it;
    it2--;
    set<pair<int,int> > ::iterator it3 = nega[k].end();
    while (it2->second <= y) {
      if (it2 != nega[k].begin()) {
        it3 = it2;
        it3--; 
      } else {
        it3 = nega[k].end();
      }
      nega[k].erase(it2);
      if (it3 == nega[k].end()) {
        break;
      }
      it2 = it3;
    }
  }
}

void insertPosi(int x, int y, int k) {
  set<pair<int,int> >::iterator it = posi[k].lower_bound(make_pair(x, -1000000000));
  set<pair<int,int> >::iterator it2 = posi[k].end();
  if (it != posi[k].end() && it->first == x && it->second < y) {
    posi[k].erase(it);
  }
  posi[k].insert(make_pair(x,y));
  it = posi[k].find(make_pair(x,y));
  if (it != posi[k].begin()) {
    it2 = it;
    it2--;
    if (it2->second >= it->second) {
      posi[k].erase(it);
      return;
    }
  }
  it2 = it;
  it2++;
  while (it2 != posi[k].end()) {
    set<pair<int,int> >::iterator it3;
    it3 = it2;
    it3++;
    if (it2->second <= y) {
      posi[k].erase(it2);
    } else {
      break;
    }
    it2 = it3;
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  sum[0] = arr[0];
  for (int i = 1; i < n; i++) {
    sum[i] = sum[i-1] + arr[i];
  }
  for (int i = 0; i < 405; i++) {
    for (int j = 0; j < 405; j++) {
      for (int k = 0; k < 55; k++) {
        dp[i][j][k] = -1000000000;
      }
    }
  }
  int res = 0;
  for (int j = 0; j < n; j++) {
    for (int i = 0; i <= j; i++) {
      dp[i][j][1] = 0;
    }
  }
  for (int j = 1; j < n; j++) {
    for (int k = 1; k <= m; k++) {
      for (int i = 0; i < j; i++) {
        insertPosi(getsum(i,j - 1), dp[i][j-1][k] - getsum(i,j-1), k);
        insertNega(getsum(i,j - 1), dp[i][j-1][k] + getsum(i,j-1), k);
      }
    }
    for (int k = 2; k <= m; k++) {
      for (int i = j; i < n; i++) {
        //try positive
        int sum = getsum(j, i);
        set<pair<int,int> >::iterator it = posi[k-1].upper_bound(make_pair(sum, 1000000000));
        if (it != posi[k-1].begin()) {
          it--;
          int mini = it->second;
          dp[j][i][k] = max(dp[j][i][k], mini + sum);
        } 
        it = nega[k-1].lower_bound(make_pair(sum, -1000000000));
        if (it != nega[k-1].end()) {
          int mini = it->second;
          dp[j][i][k] = max(dp[j][i][k], mini - sum);
        }
        if (k == m) {
          res =  max(res, dp[j][i][k]);
        }
      }
    }
  }
  printf("%d\n", res);
}