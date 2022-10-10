#include <cstdio>
#include <algorithm>
using namespace std;
int n,cur,i,j,z,r,a[(1<<24)+5];
char s[5];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%s",s);
    for (cur=j=0; j<3; j++) cur|=1<<(s[j]-'a');
    a[cur]++;
  }
  z=(1<<24)-1;
  for (j=0; j<24; j++) for (i=0; i<=z; i++) if (i&(1<<j)) a[i]+=a[i^(1<<j)];
  for (i=0; i<=z; i++) r^=(n-a[i])*(n-a[i]);
  printf("%d\n",r);
  return 0;
}