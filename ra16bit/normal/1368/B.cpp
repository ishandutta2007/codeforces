#include <bits/stdc++.h>
using namespace std;
const string c="codeforces";
long long n,i,j,k,e,cur;
int main() {
  cin>>n;
  for (i=1; ; i++) {
    for (cur=1, j=0; j<10; j++) cur*=i;
    if (cur>=n) {
      for (k=1; k<=10; k++) {
        for (cur=1, j=0; j<k; j++) cur*=i;
        for (; j<10; j++) cur*=i-1;
        if (cur>=n) {
          for (j=0; j<k; j++) for (e=0; e<i; e++) putchar(c[j]);
          for (; j<10; j++) for (e=1; e<i; e++) putchar(c[j]);
          return 0;
        }
      }
    }
  }
  return 0;
}