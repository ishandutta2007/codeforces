#include <cstdio>
#include <queue>
using namespace std;
typedef long long ll;
int n,m,x,y,i;
ll z,last;
priority_queue<ll,vector<ll>,greater<ll> > q;
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) {
    scanf("%d%d",&x,&y);
    while (!q.empty() && q.top()<=x) q.pop();
    if (q.size()<m) {
      q.push(last);
      last=z=max(last,1LL*x)+y;
    } else z=-1;
    printf("%I64d%c",z,(i==n-1)?'\n':' ');
  }
  return 0;
}