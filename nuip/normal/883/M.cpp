#include <bits/stdc++.h>
using namespace std;

int x, y;
int a, b;
int xcnt;
int ycnt;
typedef long long int LLI;

int main() {
  scanf("%d%d", &x, &y);
  scanf("%d%d", &a, &b);
  if (x == a) xcnt++;
  if (y == b) ycnt++;
  printf("%lld\n", (LLI(abs(x-a)+1+xcnt)+LLI(abs(y-b)+1+ycnt))*2);
}