#include <bits/stdc++.h>
using namespace std;

set <int> avail;
map <pair<int,int>, int> blocks;
int x[100005];
int y[100005];
int n;
long long res;
long long MOD = 1000000009;

int getblock(int x, int y) {
  if (blocks.count(make_pair(x,y)) == 0) return -1;
  return blocks[make_pair(x,y)];
}

void removeblock(int blocknum) {
}

bool critical(int blocknum) {
  if (y[blocknum] == 0) return false;
  int num = 0;
  for (int i = -1; i <= 1; i++) {
    if (getblock(x[blocknum] + i, y[blocknum] - 1) != -1) {
      ++num;
    }
  }
  return num == 1;
}

bool removable(int blocknum) {
  for (int i = -1; i <= 1; i++) {
    if (getblock(x[blocknum] + i, y[blocknum] + 1) != -1 && critical(getblock(x[blocknum] + i, y[blocknum] + 1)))
      return false;
  }
  return true;
}

void eraseblock(int blocknum) {
  blocks.erase(make_pair(x[blocknum], y[blocknum]));
  for (int i = -3; i <= 3; i++) {
    for (int j = -3; j <= 3; j++) {
      int num = getblock(x[blocknum] + i, y[blocknum] + j);
      if (num != -1) {
        avail.erase(num);
        if (removable(num)) avail.insert(num);
      }
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i  =0; i < n; i++) {
    scanf("%d %d", &x[i], &y[i]);
    blocks[make_pair(x[i], y[i])] = i;
  }
  for (int i = 0; i < n; i++) {
    if (removable(i)) avail.insert(i);
  }
  res = 0;
  for (int i = 0; i < n; i++) {
    res = (res * (long long)n) % MOD;
    if (i % 2 == 0) {
      res += *avail.rbegin();
      int num = *avail.rbegin();
//      printf("!!!%d\n", avail.size());
//      printf("%d\n", num);
      eraseblock(num);
      avail.erase(num);
    } else {
      res += *avail.begin();
      int num = *avail.begin();
//      printf("!!!%d\n", avail.size());
//      printf("%d\n", num);
      eraseblock(num);
      avail.erase(num);
    }
  }
  printf("%I64d\n", res);
  
}