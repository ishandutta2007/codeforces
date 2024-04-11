#include <cstdio>
#include <algorithm>
using namespace std;
const int MX=1000100;
int n,i,x,cnt,a[MX];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&x);
    a[x]++;
  }
  for (i=0; i+1<MX; i++) if (a[i]>0) {
    cnt+=a[i]%2;
    a[i+1]+=a[i]/2;
  }
  printf("%d\n",cnt);
  return 0;
}