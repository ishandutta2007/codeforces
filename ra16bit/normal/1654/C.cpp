#include <bits/stdc++.h>
using namespace std;
const int MX=200100;
int t,n,i,cur,a[MX];
long long s,x;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (s=i=0; i<n; i++) {
      scanf("%d",&a[i]);
      s+=a[i];
    }
    sort(a,a+n);
    reverse(a,a+n);
    cur=0;
    priority_queue<long long> q;
    q.push(s);
    bool ok=true;
    while (cur<n && q.size()<=n) {
      if (q.empty()) { ok=false; break; }
      x=q.top();
      q.pop();
      if (x==a[cur]) ++cur; else {
        q.push(x/2);
        q.push(x-x/2);
      }
    }
    if (!q.empty()) ok=false;
    puts(ok?"YES":"NO");
  }
  return 0;
}