#include<cstdio>
#include<algorithm>


using namespace std;

int n, a[1111];

int main(){
  int ans;
  scanf("%d", &n);
  for (int i=0; i<n; i++) scanf("%d", a+i);
  ans=min(a[0], a[n-1]);
  for (int i=1; i<n; i++)
    ans=min(ans, max(a[i-1], a[i]));

  printf("%d\n", ans);
  return 0;
}