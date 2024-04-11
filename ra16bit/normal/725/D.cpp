#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,i,j,r,k[300300];
ll t[300300],w[300300];
priority_queue<ll, vector<ll>, greater<ll> > q;
bool cmp(int i, int j) {
  if (t[i]!=t[j]) return t[i]>t[j];
  return i<j;
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%I64d%I64d",&t[i],&w[i]);
    k[i]=i;
  }
  sort(k,k+n,cmp);
  for (i=0; i<n; i++) if (k[i]==0) break;
  for (j=0; j<i; j++) q.push(w[k[j]]-t[k[j]]+1);
  r=++i;
  while (!q.empty()) {
    t[0]-=q.top();
    if (t[0]<0) break;
    q.pop();
    for (; i<n && t[k[i]]>t[0]; i++) q.push(w[k[i]]-t[k[i]]+1);
    r=min(r,int(q.size())+1);
  }
  printf("%d\n",r);
  return 0;
}