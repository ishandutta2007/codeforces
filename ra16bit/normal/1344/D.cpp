#include <bits/stdc++.h>
using namespace std;
int n,x,i,a[100100],b[100100];
priority_queue<pair<long long, int>> q;
long long m,mx,mn,cur,cnt,le,ri,h;
int fnd(int i, long long v) {
  int lft=0,rgh=a[i];
  while (lft<rgh) {
    int mid=(lft+rgh)/2+1;
    cur=a[i]-3LL*mid*(mid+1LL)-1LL;
    if (cur<v) rgh=mid-1; else lft=mid;
  }
  return rgh;
}
int main() {
  scanf("%d%I64d",&n,&m);
  for (i=0; i<n; i++) {
    scanf("%d",&a[i]);
    q.push({a[i]-1LL,i});
    cur=a[i]-3LL*a[i]*(a[i]+1LL)-1LL;
    if (i) {
      mn=min(mn,cur);
      mx=max(mx,a[i]-1LL);
    } else {
      mn=cur;
      mx=a[i]-1LL;
    }
  }
  le=0; ri=mx-mn;
  while (le<ri) {
    h=(le+ri)/2;
    for (cnt=i=0; i<n; i++) cnt+=fnd(i,mx-h);
    if (cnt<m) le=h+1; else ri=h;
  }
  for (i=0; i<n; i++) {
    b[i]=fnd(i,mx-ri+1);
    m-=b[i];
  }
  for (i=0; i<n && m>0; i++) {
    x=min(1LL*fnd(i,mx-ri)-b[i],m);
    b[i]+=x;
    m-=x;
  }
  for (i=0; i<n; i++) printf("%d ",b[i]);
  return 0;
}