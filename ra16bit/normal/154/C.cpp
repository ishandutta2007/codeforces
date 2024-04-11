#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,i,x,y;
vector <int> g[1000010];
long long j,cur,res,s[1000010],a[1000010],b[1000010];
void solve(long long *a) {
  sort(a,a+n);
  for (i=0; i<n; i=j) {
    for (j=i; j<n && a[j]==a[i]; j++);
    res+=(j-i)*(j-i-1);
  }
}
int main() {
  scanf("%d%d",&n,&m);
  for (cur=37, i=0; i<n; i++) b[i]=s[i]=(cur*=37);
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
    x--; y--;
    a[x]+=s[y]; b[x]+=s[y];
    a[y]+=s[x]; b[y]+=s[x];
  }
  solve(a);
  solve(b);
  printf("%I64d\n",res/2);
  return 0;
}