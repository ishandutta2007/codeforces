#include <bits/stdc++.h>
using namespace std;

int n,k;
char c[1000005];
int z[1000005];

int main() {
  scanf("%d %d", &n, &k);
  scanf("%s",c);
  if (k == 1) {
    for (int i = 0; i < n; i++) {
      printf("1");
    }
    printf("\n");
    return 0;
  }
  int l = 0, r = 0;
  for (int i = 1; i < n; i++) {
    if (i > r) {
      l = r = i;
      while (r < n && c[r-l] == c[r]) r++;
      z[i] = r - l; r--;
    } else {
      int k = i - l;
      if (z[k] < r - i + 1) z[i] = z[k];
      else {
        l = i;
        while (r < n && c[r-l] == c[r]) r++;
        z[i] = r - l;
        r--;
      }
    }
  }
  vector <pair<int,int> > can;

  for (int i = 1; i < n; i++) {
    int numprev = i;
    int numsuf = z[i];
    if ((long long)numsuf >= (long long)(k-1) * numprev) {
      can.push_back(make_pair(k*numprev - 1, min((k+1)*numprev - 1, numprev + numsuf - 1)));
    }
  }
  int events[1000005];
  memset(events, 0, sizeof(events));
  for (int i = 0; i < can.size(); i++) {
    events[can[i].first]++;
    events[can[i].second+1]--;
  }
  int num = 0;
  for (int i = 0; i < n; i++) {
    num+=events[i];
    if (num > 0) {
      printf("1");
    } else {
      printf("0");
    }
  }
  printf("\n");

}