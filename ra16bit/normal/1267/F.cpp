#include <bits/stdc++.h>
using namespace std;
int n,m,x,y,i,j,v,u,p,q,r,a[200200],b[200200],c[200200];
vector<int> g[200200];
priority_queue<int,vector<int>,greater<int>> qq;
int main() {
    scanf("%d%d%d%d",&n,&m,&x,&y);
    for (i=0; i<x; i++) {
      scanf("%d",&a[i]);
      c[a[i]]++;
    }
    for (i=0; i<y; i++) {
      scanf("%d",&b[i]);
      c[b[i]]++;
    }
    if (x>=m || y>=n) { puts("No"); return 0; }
    c[a[x-1]]+=m-1-x;
    c[b[y-1]]+=n-y;
    //for (i=1; i<=n+m; i++) printf("%d,",c[i]); puts("");
    for (i=1; i<=n+m; i++) if (c[i]==0) qq.push(i);
    for (p=q=r=0; !qq.empty() && r<n+m-1; r++) {
      v=qq.top();
      qq.pop();
      if (v<=n) {
        u=b[q];
        if (q+1<y) q++;
      } else {
        u=a[p];
        if (p+1<x) p++;
      }
      g[v].push_back(u);
      if (--c[u]==0) qq.push(u);
      //printf("%d -> %d\n",v,u);
    }
    //g[a[x-1]].push_back(b[y-1]);
    if (r==n+m-1) {
      puts("Yes");
      for (i=1; i<=n+m; i++) for (j=0; j<g[i].size(); j++) printf("%d %d\n",i,g[i][j]);
    } else puts("No");
    return 0;
}