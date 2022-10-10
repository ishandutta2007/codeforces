#include <bits/stdc++.h>
using namespace std;
long long cur,l,r,t,x,y,d,lim;
bool a[1000100];
int main() {
  cin>>cur>>l>>r>>t>>x>>y;
  if (cur+y<=r) cur+=y;
  if (cur-x<l) { puts("No"); return 0; }
  if (x==y) { puts("Yes"); return 0; }
  if (x>y) {
    cur-=x;
    --t;
    d=(cur-l)/(x-y);
    puts((d>=t)?"Yes":"No");
    return 0;
  }
  lim=r-y;
  d=(r-cur)/(y-x);
  cur+=d*(y-x);
  t-=d;
  while (t>0) {
    d=(cur-lim+x-1)/x;
    if (d>t) {
      cur-=t*x;
      puts((cur>=l)?"Yes":"No");
      return 0;
    }
    cur-=d*x;
    t-=d;
    if (cur<l) { puts("No"); return 0; }
    cur+=y;
    if (a[r-cur]) break;
    a[r-cur]=true;
  }
  puts("Yes");
  return 0;
}