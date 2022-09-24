#include<cstdio>
#include<algorithm>

using namespace std;

int n, a[100010], b[100010];

int main(){
  scanf("%d", &n);
  for (int i=0; i<n; i++) scanf("%d", a+i), b[i]=a[i] ;
  sort(b, b+n);
  int cnt=0;
  for (int i=0; i<n; i++) if (a[i]!=b[i]) cnt++;
  puts(cnt<3?"YES":"NO");

  return 0;
}