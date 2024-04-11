#include <bits/stdc++.h>
using namespace std;
int x,y,z,a,b,c,d,e,f;
int main() {
  scanf("%d%d%d%d%d%d",&x,&y,&z,&a,&b,&c);
  d=x-y;
  if (d<0) d=-d;
  f=z-x;
  if (f<0) f=-f;
  e=(f+d)*b+3*c;
  puts((e<=d*a)?"YES":"NO");
  return 0;
}