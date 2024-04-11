#include <bits/stdc++.h>
using namespace std;
int i,x,a[7],b[7];
void print(int x, int y) {
  puts("YES");
  if (b[x]<b[y]) swap(x,y);
  for (i=0; i<b[y]; i++) printf("%d %d ",x,y);
  for (i=0; i<b[x]-b[y]; i++) printf("%d ",x);
}
int main() {
  for (i=0; i<4; i++) {
    scanf("%d",&a[i]);
    b[i]=a[i];
  }
  if ((b[0]==b[1]+1 || b[1]==b[0]+1) && b[2]==0 && b[3]==0) {
    print(0,1);
    return 0;
  }
  if ((b[2]==b[1]+1 || b[1]==b[2]+1) && b[0]==0 && b[3]==0) {
    print(1,2);
    return 0;
  }
  if ((b[3]==b[2]+1 || b[2]==b[3]+1) && b[0]==0 && b[1]==0) {
    print(2,3);
    return 0;
  }
  if (b[1]<b[0] || b[2]<b[3]) { puts("NO"); return 0; }
  b[1]-=b[0];
  b[2]-=b[3];
  x=min(b[1],b[2]);
  b[1]-=x;
  b[2]-=x;
  if (b[1]>1 || b[2]>1) { puts("NO"); return 0; }
  puts("YES");
  if (b[1]==1) printf("1 ");
  for (i=0; i<a[0]; i++) printf("0 1 ");
  for (i=0; i<x; i++) printf("2 1 ");
  for (i=0; i<a[3]; i++) printf("2 3 ");
  if (b[2]==1) printf("2");
  return 0;
}