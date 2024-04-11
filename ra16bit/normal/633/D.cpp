#include <bits/stdc++.h>
using namespace std;
int n,i,j,it,x,y,z,p,c,r,cnt,a[1010],u[1010];
bool rx,ry;
void solve() {
    u[x=i]=++it;
    u[y=j]=it;
    rx=ry=false;
    for (c=2; c<n; c++) {
      swap(p,z); z+=p;
      if (z>=0) {
        if (!ry) {
          while (y>=0 && (a[y]>z || (a[y]==z && u[y]==it))) y--;
          if (y>=0 && a[y]==z && u[y]!=it) {
            u[y]=it;
            continue;
          } else {
            ry=true;
            y++;
          }
        }
        if (ry) {
          while (y<n && (a[y]<z || (a[y]==z && u[y]==it))) y++;
          if (y<n && a[y]==z && u[y]!=it) {
            u[y]=it;
            continue;
          } else break;
        }
      } else {
        if (!rx) {
          while (x<n && (a[x]<z || (a[x]==z && u[x]==it))) x++;
          if (x<n && a[x]==z && u[x]!=it) {
            u[x]=it;
            continue;
          } else {
            rx=true;
            x--;
          }
        }
        if (rx) {
          while (x>=0 && (a[x]>z || (a[x]==z && u[x]==it))) x--;
          if (x>=0 && a[x]==z && u[x]!=it) {
            u[x]=it;
            continue;
          } else break;
        }
      }
    }
    r=max(r,c);
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&a[i]);
    if (a[i]==0) cnt++;
  }
  sort(a,a+n);
  for (i=0; i<n; i++) for (j=i+1; j<n; j++) if (a[i]!=0 || a[j]!=0) {
    p=a[i];
    z=a[j];
    solve();
    p=a[j];
    z=a[i];
    solve();
  } else r=max(r,cnt);
  printf("%d\n",r);
  return 0;
}