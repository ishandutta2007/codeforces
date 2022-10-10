#include <bits/stdc++.h>
using namespace std;
typedef pair<long long,int> pli;
const int MX=400200;
int n,ii,i,k[MX];
long long l[MX],r[MX],t[MX],pos,res;
priority_queue<pli,vector<pli>,greater<pli>> q;
bool cmp(int i, int j) { return l[i]<l[j]; }
void calc(long long x) {
  long long now;
  while (!q.empty() && r[q.top().second]<=x) {
    int cur=q.top().second;
    //pos=max(pos,l[cur]);
    now=(r[cur]-pos)/t[cur];
    if (now>0) {
      pos+=now*t[cur];
      res+=now;
    }
    q.pop();
  }
  //while (!q.empty() && /*min(*/pos/*,x)*/+t[q.top().second]>r[q.top().second]) q.pop();
  while (!q.empty() && pos<=x) {
    int cur=q.top().second;
    //pos=max(pos,l[cur]);
    now=(min(x+t[cur],r[cur])-pos)/t[cur];
    if (now>0) {
      pos+=now*t[cur];
      res+=now;
    }
    if (pos<=x) q.pop();
  }
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%I64d%I64d%I64d",&l[i],&r[i],&t[i]);
    k[i]=i;
  }
  sort(k,k+n,cmp);
  for (ii=0; ii<n; ii++) {
    i=k[ii];
    calc(l[i]);
    assert(l[i]+t[i]<=r[i]);
    if (pos<=l[i]) {
      pos=l[i]+t[i];
      res++;
    } else pos=min(pos,l[i]+t[i]);
    q.push({t[i],i});
  }
  calc(2000000000000000000LL);
  //printf("pos = %d; res = %d; x = %d\n",int(pos),int(res),int(l[i]));
  printf("%I64d\n",res);
  return 0;
}