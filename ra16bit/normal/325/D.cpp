#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int dx[8]={-1,-1,-1,0,0,1,1,1};
const int dy[8]={-1,0,1,-1,1,-1,0,1};
int n,m,q,num,x,y,nx,ny,k,res,a[3003][6006],p[600300];
vector<int> v;
int fs(int i) {
  if (p[i]==i || p[i]==num) return i;
  return p[i]=fs(p[i]);
}
void un(int y) {
  int x=num;
  v.push_back(y);
  p[y]=x;
}
int main() {
  scanf("%d%d%d",&n,&m,&q);
  m*=2;
  while (q--) {
    scanf("%d%d",&x,&y);
    a[x][--y]=++num;
    p[num]=num;
    v.clear();
    for (k=0; k<8; k++) {
      nx=x+dx[k];
      if (nx<1 || nx>n) continue;
      ny=(y+dy[k]+m)%m;
      if (a[nx][ny]) un(p[fs(a[nx][ny])]);
    }
    for (k=0; k<8; k++) {
      nx=x+dx[k];
      if (nx<1 || nx>n) continue;
      ny=(y+m/2+dy[k]+m)%m;
      if (a[nx][ny] && p[fs(a[nx][ny])]==num) break;
    }
    if (k<8) {
      a[x][y]=0;
      for (k=0; k<v.size(); k++) p[v[k]]=v[k];
    } else {
      a[x][y+m/2]=++num;
      p[num]=num;
      for (k=0; k<8; k++) {
        nx=x+dx[k];
        if (nx<1 || nx>n) continue;
        ny=(y+m/2+dy[k]+m)%m;
        if (a[nx][ny]) un(p[fs(a[nx][ny])]);
      }
      res++;
    }
  }
  printf("%d\n",res);
  return 0;
}