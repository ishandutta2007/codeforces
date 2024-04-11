#include <bits/stdc++.h>
using namespace std;
int x,y,z,i,j;
int main() {
  scanf("%d%d%d",&x,&y,&z);
  for (i=0; i*x<=z; i++) for (j=0; i*x+j*y<=z; j++) if (i*x+j*y==z) { puts("Yes"); return 0; }
  puts("No");
  return 0;
}