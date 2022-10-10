#include <cstdio>
using namespace std;
int x,z,i;
int main() {
  scanf("%d",&x);
  if (x<0) x=-x;
  for (i=z=0; z<x || z%2!=x%2; i++) z+=i+1;
  printf("%d\n",i);
  return 0;
}