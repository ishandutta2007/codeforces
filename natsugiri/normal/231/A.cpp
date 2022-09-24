#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long LL;

int n;
int a,b,c,r;
int main(){
  scanf("%d", &n);

  for (;n--;) {
      scanf("%d%d%d", &a, &b, &c);
      if (a+b+c>1) r++;
  }
  printf("%d\n", r);
  return 0;
}