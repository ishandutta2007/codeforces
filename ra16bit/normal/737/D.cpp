#include <cstdio>
#include <algorithm>
using namespace std;
const int inf=-2000000000;
int n,i,a,s[4004],r[4004][90][90];
bool u[4004][90][90];
int F(int i, int jj, int k) {
  int j=n+1-i-jj;
  if (i+k>j+1) return 0;
  if (u[i][jj][k]) return r[i][jj][k];
  u[i][jj][k]=true;
  int cur=inf;
  if (i+k<=j-k+1) {
    int y=F(i+k,jj,k)-s[j]+s[j-k];
    if (i+k<=j-k) y=min(y,F(i+k,jj+1,k+1)-s[j]+s[j-k-1]);
    cur=max(cur,s[i+k-1]-s[i-1]+y);
  } else cur=max(cur,s[i+k-1]-s[i-1]);
  if (i+k+1<=j-k) {
    int y=F(i+k+1,jj,k+1)-s[j]+s[j-k-1];
    if (i+k+1<=j-k-1) y=min(y,F(i+k+1,jj+1,k+2)-s[j]+s[j-k-2]);
    cur=max(cur,s[i+k]-s[i-1]+y);
  } else if (i+k<=j) cur=max(cur,s[i+k]-s[i-1]);
  r[i][jj][k]=cur;
  return cur;
}
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) {
    scanf("%d",&a);
    s[i]=s[i-1]+a;
  }
  printf("%d\n",F(1,0,1));
  return 0;
}