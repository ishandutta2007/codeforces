#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, m;
int s; long long t;

long long lst[N];
int nxt[N];

void go() {
  if (s < m) s = (t-- + s) % n;
  else s = (-t-- + s) % n;
  
  if (s < 0) s += n;
}

int main() {
  scanf("%d %d", &n, &m);
  scanf("%d %lld", &s, &t);
  --s;
  
  for (int i=t%n; i>0; i--) go();
  
  while (t > 0) {
    if (lst[s] > 0) {
      long long cyc = t - lst[s];
      t %= cyc;
      
      while (t > 0) {
        s = nxt[s];
        t -= n;
      }
      
      return 0 * printf("%d\n", s+1);
    }
    
    lst[s] = t;
    int tmp = s;
    for (int i=0; i<n; i++) go();
    nxt[tmp] = s;
  }
  
  printf("%d\n", s+1);
  return 0;
}