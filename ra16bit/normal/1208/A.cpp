#include <bits/stdc++.h>
using namespace std;
int f[6],x,t;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d%d",&f[0],&f[1],&x);
    f[2]=(f[0]^f[1]);
    printf("%d\n",f[x%3]);
  }
  return 0;
}