#include <bits/stdc++.h>
using namespace std;
int n,m,cur,it,i,j,w,a[55],b[55];
vector<vector<int>> r;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  for (it=0; it<n; it++) {
    vector<int> d;
    if (a[n-1]==n) {
      for (j=n-1; j>=0; j--) {
        if (a[j]!=j+1) break;
        d.push_back(1);
      }
      if (d.size()==n) break;
      for (cur=0, w=j+1; j>=0; j--) {
        ++cur;
        if (j==0 || a[j]==w) {
          d.push_back(cur);
          cur=0;
        }
      }
      reverse(d.begin(),d.end());
    } else if (a[0]==n) {
      for (j=0; j<n; j++) {
        if (a[j]!=n-j) break;
        d.push_back(1);
      }
      for (cur=0, w=n-j; j<n; j++) {
        ++cur;
        if (j+1==n || a[j]==w) {
          d.push_back(cur);
          cur=0;
        }
      }
    } else {
      for (cur=j=1; j<n; j++) if (a[j]==n) {
        d.push_back(cur);
        cur=1;
      } else cur++;
      d.push_back(cur);
    }
    m=0; cur=n;
    for (i=int(d.size())-1; i>=0; i--) {
      cur-=d[i];
      for (j=0; j<d[i]; j++) b[m++]=a[cur+j];
    }
    for (i=0; i<n; i++) a[i]=b[i];
    //for (i=0; i<n; i++) printf("%d ",a[i]); puts("");
    r.push_back(d);
  }
  printf("%d\n",int(r.size()));
  for (i=0; i<r.size(); i++, puts("")) {
    printf("%d",int(r[i].size()));
    for (j=0; j<r[i].size(); j++) printf(" %d",r[i][j]);
  }
  return 0;
}