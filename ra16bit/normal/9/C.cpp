#include <cstdio>
using namespace std;
int n,r;
void rec(int l, int x) {
  if (l==10) {
    if (x<=n) r++;
    return;
  }
  rec(l+1,x*10);
  rec(l+1,x*10+1);
}
int main() {
  scanf("%d",&n);
  rec(0,0);
  printf("%d\n",r-1);
  return 0;

}