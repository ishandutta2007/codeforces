#include <cstdio>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
int n,i,x,best,a[100100];
priority_queue<pii, vector<pii>, greater<pii> > q;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  q.push(make_pair(1,0));
  q.push(make_pair(1,n-1));
  a[0]=a[n-1]=1;
  for (i=1; i<n-1; i++) q.push(make_pair(a[i],i));
  while (!q.empty()) {
    x=q.top().first;
    i=q.top().second;
    q.pop();
    if (a[i]!=x) continue;
    best=x;
    if (i>0 && a[i-1]>a[i]+1) {
      a[i-1]=a[i]+1;
      q.push(make_pair(a[i-1],i-1));
    }
    if (i<n-1 && a[i+1]>a[i]+1) {
      a[i+1]=a[i]+1;
      q.push(make_pair(a[i+1],i+1));
    }
  }
  printf("%d\n",best);
  return 0;
}