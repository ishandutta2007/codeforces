#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int t,n,m,x,i,cur,a[100100];
priority_queue<pii,vector<pii>,greater<pii>> q;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d%d",&n,&m,&x);
    puts("YES");
    for (i=0; i<n; i++) {
      scanf("%d",&a[i]);
      if (i<m) {
        printf("%d ",i+1);
        q.push({a[i],i+1});
      }
    }
    for (i=m; i<n; i++) {
      cur=q.top().first;
      x=q.top().second;
      printf("%d ",x);
      q.pop();
      q.push({cur+a[i],x});
    }
    puts("");
    while (!q.empty()) q.pop();
  }
  return 0;
}