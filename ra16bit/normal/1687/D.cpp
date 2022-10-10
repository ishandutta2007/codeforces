#include <bits/stdc++.h>
using namespace std;
const int MX=1000100,MV=2*MX;
int n,i,j,sz,p[MX],nxt[MX],a[MX],b[MX];
vector<int> v[MV];
long long le,ri,lft,rgh,cur,c;
int fs(int x) {
  if (x!=p[x]) p[x]=fs(p[x]);
  return p[x];
}
long long sqr(long long x) { return x*x; }
int main() {
  scanf("%d",&n);
  for (j=i=0; i<n; i++) {
    scanf("%d",&a[i]);
    b[i]=a[i];
    p[i]=i;
    if (i>0 && a[i]!=a[j]) {
      nxt[j]=i;
      v[a[i]-a[j]].push_back(j);
      j=i;
    }
  }
  nxt[n-1]=-1;
  for (sz=1; sz<MV; sz++) {
    for (int j: v[sz]) {
      i=nxt[j];
      p[i]=fs(j);
      b[p[i]]=b[i];
      nxt[p[i]]=nxt[i];
    }
    le=sqr(sz);
    ri=le+sz;
    if (a[0]>ri) continue;
    ri-=a[0];
    le=max(le-a[0],0LL);
    for (cur=sz, i=0; i!=-1 && le<=ri; cur++) {
      lft=sqr(cur);
      rgh=lft+cur;
      if (a[i]+ri>=lft && a[i]+le<=rgh) {
        for (j=i; nxt[j]!=-1 && b[nxt[j]]-a[i]<=cur; j++);
        //for (int k=i+1; k<=j; k++) p[k]=i;
        //b[i]=b[j];
        //nxt[i]=nxt[j];
        le=max(le,lft-a[i]);
        ri=min(ri,rgh-b[j]);
        if (nxt[j]!=-1) {
          rgh+=cur;
          c=min(b[j]+cur,a[nxt[j]]-1LL);
          ri=min(ri,rgh-c);
        }
        i=nxt[j];
      } else if (a[i]+ri<lft) break;
    }
    if (i==-1 && le<=ri) {
      printf("%lld\n",le);
      break;
    }
  }
  return 0;
}