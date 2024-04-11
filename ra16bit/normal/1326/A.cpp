#include <bits/stdc++.h>
using namespace std;
int t,n,i,cur;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    if (n==1) { puts("-1"); continue; }
    for (cur=i=0; i<n-2; i++) cur=(cur*10+2)%3;
    if ((cur*100+23)%3==0) {
      for (i=0; i<n-2; i++) putchar('2');
      puts("33");
    } else {
      for (i=0; i<n-1; i++) putchar('2');
      puts("3");
    }
  }
  return 0;
}