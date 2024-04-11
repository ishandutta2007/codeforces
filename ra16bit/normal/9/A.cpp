#include <cstdio>
using namespace std;
int x,y;
int main() {
  scanf("%d%d",&x,&y);
  if (y>x) x=y;
  x=7-x; y=6;
  if (x%2==0) { x/=2; y/=2; }
  if (x%3==0) { x/=3; y/=3; }
  printf("%d/%d\n",x,y);
  return 0;
}