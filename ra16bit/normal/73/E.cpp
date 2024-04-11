#include <cstdio>
#include <set>
using namespace std;
const int mx=2000000;
int i,j,n,r,x,y;
bool a[mx];
set <int> s;
int main() {
  for (i=2; i<mx; i++) if (!a[i]) for (j=i+i; j<mx; j+=i) a[j]=true;
  scanf("%d%d",&n,&x);
  if (x==2) { puts("0"); return 0; }
  for (i=0; i<n; i++) {
    scanf("%d",&y);
    if (y==1) { puts("1"); return 0; }
    s.insert(y);
  }
  if (x>=mx) { puts("-1"); return 0; }
  for (i=2; i<x; i++) if (!a[i]) {
    if (s.find(i)==s.end()) { puts("-1"); return 0; } else r++;
  }
  printf("%d\n",r);
  return 0;
}