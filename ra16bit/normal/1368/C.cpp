#include <bits/stdc++.h>
using namespace std;
int n,i;
void print(int i, int j, bool fi=false) {
  if (fi) printf("%d %d\n",i,j);
  printf("%d %d\n",i+1,j);
  printf("%d %d\n",i,j+1);
  printf("%d %d\n",i+2,j);
  printf("%d %d\n",i,j+2);
  printf("%d %d\n",i+2,j+1);
  printf("%d %d\n",i+1,j+2);
  printf("%d %d\n",i+2,j+2);
}
int main() {
  scanf("%d",&n);
  printf("%d\n",7*(n+1)+1);
  print(0,0,true);
  for (i=1; i<=n; i++) print(2*i,2*i);
  return 0;
}