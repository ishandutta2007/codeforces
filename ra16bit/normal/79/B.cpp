#include <cstdio>
#include <utility>
using namespace std;
int n,m,i,j,k,t,r;
pair <int, int> a[1010],b;
int main() {
  scanf("%d%d%d%d",&n,&m,&k,&t);
  for (i=0; i<k; i++) scanf("%d%d",&a[i].first,&a[i].second);
  while (t--) {
    scanf("%d%d",&b.first,&b.second);
    for (r=j=0; j<k; j++) if (b==a[j]) {
      puts("Waste"); break;
    } else if (a[j]<b) r++;
    if (j<k) continue;
    r=(b.first-1)*m+b.second-1-r;
    if (r%3==0) puts("Carrots"); else
    if (r%3==1) puts("Kiwis"); else puts("Grapes");
  }
  return 0;
}