#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
int a[N];

int main() {
  scanf("%d", &n);
  for (int i=0; i<n; i++) scanf("%d", a + i);
  
  priority_queue<long long, vector<long long>, greater<long long>> pq;
  
  for (int i=0; i<n; i++) pq.push(a[i]);
  long long ans = 0;
  
  while (pq.size() > 1) {
    int cnt = 2 + (pq.size() & 1);
    
    long long sum = 0;
    for (int i=0; i<cnt; i++) {
      sum += pq.top();
      pq.pop();
    }
    
    ans += sum;
    pq.push(sum);
  }
  
  printf("%lld\n", ans);
  
  return 0;
}