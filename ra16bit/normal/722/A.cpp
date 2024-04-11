#include <bits/stdc++.h>
using namespace std;
int a,y,z;
int main() {
  scanf("%d",&a);
  scanf("%d:%d",&y,&z);
  if (z/10>=6) z%=10;
  if (a==12) {
    if (y==0) y=1;
    if (y>12) {
      y%=10;
      if (y==0) y=10;
    }
  } else if (y>23) y%=10;
  printf("%02d:%02d\n",y,z);
  return 0;
}