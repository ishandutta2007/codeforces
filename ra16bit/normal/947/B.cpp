#include <bits/stdc++.h>
using namespace std;
int n,i,x,a[100100];
long long s,c;
priority_queue<long long, vector<long long>, greater<long long>> q;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  for (i=0; i<n; i++) {
    q.push(a[i]+s);
    scanf("%d",&x);
    for (c=0; !q.empty() && q.top()<=s+x; ) {
      c+=q.top()-s;
      q.pop();
    }
    s+=x;
    c+=((long long)(q.size()))*x;
    printf("%lld ",c);
  }
  return 0;
}