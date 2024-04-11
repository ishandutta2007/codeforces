#include <bits/stdc++.h>
using namespace std;
int n,i,x,y,cnt[4][4],px[3],py[3];
long long r;
int gcd(int a, int b) {
  return b?gcd(b,a%b):a;
}
void rec(int l, int b, long long cur) {
  if (l==3) {
    b+=gcd(abs(px[2]-px[0]),abs(py[2]-py[0]));
    if (b%4==0) r+=cur;
    return;
  }
  for (int x=0; x<4; x++) for (int y=0; y<4; y++) if (cnt[x][y]>0) {
    long long nxt=cur*cnt[x][y];
    --cnt[x][y];
    px[l]=x;
    py[l]=y;
    rec(l+1,b+((l==0)?0:gcd(abs(x-px[l-1]),abs(y-py[l-1]))),nxt);
    ++cnt[x][y];
  }
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d",&x,&y);
    ++cnt[x%4][y%4];
  }
  rec(0,0,1);
  printf("%lld\n",r/6);
  return 0;
}