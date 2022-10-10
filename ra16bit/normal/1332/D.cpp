#include <bits/stdc++.h>
using namespace std;
const int MX=(1<<17);
int k;
int main() {
  scanf("%d",&k);
  puts("2 3");
  printf("%d %d %d\n",MX*2-1,MX,0);
  printf("%d %d %d\n",k,MX*2-1,MX-1);
  return 0;
}