#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,a[1010],f[1010][1010];
int F(int i, int j) {
  if (f[i][j]) return f[i][j];
  if (j==0) return f[i][j]=a[i];
  if (j==1) return f[i][j]=max(a[i],a[j]);
  f[i][j]=min(F(j,j-2)+max(a[i],a[j-1]),F(j-1,j-2)+max(a[i],a[j]));
  return f[i][j]=min(f[i][j],F(i,j-2)+max(a[j],a[j-1]));
}
void solve(int i, int j) {
  if (j==0) printf("%d\n",n-i+1); else 
  if (j==1) printf("%d %d\n",n-i+1,n-j+1); else
  if (f[i][j]==f[j][j-2]+max(a[i],a[j-1])) {
    printf("%d %d\n",n-i+1,n-j+2);
    solve(j,j-2);
  } else if (f[i][j]==f[i][j-2]+max(a[j],a[j-1])) {
    printf("%d %d\n",n-j+1,n-j+2);
    solve(i,j-2);
  } else {
    printf("%d %d\n",n-i+1,n-j+1);
    solve(j-1,j-2);
  }
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[n-i]);
  printf("%d\n",F(n,n-1));
  solve(n,n-1);
  return 0;
}