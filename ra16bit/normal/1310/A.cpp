#include <bits/stdc++.h>
using namespace std;
int n,i,ii,cur,a[200200],t[200200],k[200200];
priority_queue<int> q;
long long s,r;
bool cmp(int i, int j) { return a[i]<a[j]; }
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) { scanf("%d",&a[i]); k[i]=i; }
  for (i=0; i<n; i++) scanf("%d",&t[i]);
  sort(k,k+n,cmp);
  for (cur=s=ii=0; ii<n; ii++) {
    i=k[ii];
	while (!q.empty() && cur<a[i]) {
	  s-=q.top();
	  r+=s;
	  q.pop();
	  cur++;
	}
	if (cur<a[i]) cur=a[i];
	q.push(t[i]);
	s+=t[i];
  }
  while (!q.empty()) {
	s-=q.top();
	r+=s;
	q.pop();
  }
  cout<<r;
  return 0;
}