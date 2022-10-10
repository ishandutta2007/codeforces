#include <bits/stdc++.h>
using namespace std;
int t,n,i,j,x,pos,ops,ans[2020],a[2020],cnt[2020];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (i=0; i<=n; i++) cnt[i]=0;
    for (i=0; i<n; i++) {
      scanf("%d",&a[i]);
      ++cnt[a[i]];
    }
    priority_queue<int,vector<int>,greater<int>> q;
    for (ops=i=0; i<=n; i++) if (cnt[i]==0) q.push(i);
    for (pos=n, i=0; i<n; i++) if (a[i]!=i) { pos=i; break; }
    while (pos<n) {
      if (q.top()==n) {
        ans[ops++]=pos;
        q.pop();
        --cnt[a[pos]];
        q.push(a[pos]);
        a[pos]=n;
        ++cnt[n];
      }
      x=q.top();
      ans[ops++]=x;
      q.pop();
      if (--cnt[a[x]]==0) q.push(a[x]);
      for (a[x]=x; pos<n && a[pos]==pos; pos++);
    }
    printf("%d\n",ops);
    for (i=0; i<ops; i++) printf("%d ",ans[i]+1);
    puts("");
  }
  return 0;
}