#include <bits/stdc++.h>
using namespace std;
int n,q,x,y,m,r,i,z;
vector<int> a[300300];
bool u[300300];
int main() {
  scanf("%d%d",&n,&q);
  while (q--) {
    scanf("%d%d",&x,&y);
    if (x==1) {
      a[y].push_back(m);
      m++; r++;
    } else if (x==2) {
      for (i=int(a[y].size())-1; i>=0; i--) {
        if (u[a[y][i]]) break;
        u[a[y][i]]=true; r--;
      }
    } else for (; z<y; z++) if (!u[z]) {
      u[z]=true; r--;
    }
    printf("%d\n",r);
  }
  return 0;
}