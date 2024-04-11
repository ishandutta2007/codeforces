#include <bits/stdc++.h>
using namespace std;
int n,m,i,a[1000100],b[1000100],r[1000100];
long double p=1,s;
priority_queue<int> q;
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<=n; i++) { scanf("%d",&a[i]); a[i]*=100; }
  for (i=1; i<=n; i++) scanf("%d",&b[i]);
  for (i=n; i>0; i--) {
    q.push(a[i]);
	bool was=false;
    while (!q.empty() && q.top()>b[i]) {
	  was=true;
	  q.pop();
	}
	if (was) q.push(b[i]);
    r[i]=q.top();
  }
  sort(r+1,r+n+1);
  reverse(r+1,r+n+1);
  p*=m; p/=n;
  s=p*r[n];
  for (i=n-1; i>=m; i--) {
    p/=i; p*=i-m+1;
    s+=p*r[i];
  }
  printf("%.10lf\n",double(s));
  return 0;
}