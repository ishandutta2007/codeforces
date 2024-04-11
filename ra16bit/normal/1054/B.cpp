#include <bits/stdc++.h>
using namespace std;
int n,a,cur,i;
int main() {
  scanf("%d",&n);
  for (cur=i=0; i<n; i++) {
    scanf("%d",&a);
    if (a>cur) {
      printf("%d\n",i+1);
      return 0;
    }
    if (a==cur) cur++;
  }
  puts("-1");
  return 0;
}