#include <bits/stdc++.h>
using namespace std;
const int MX=200100;
int n,m,i,x,y,sz[2],b[MX];
vector<int> pos,neg,v[2][20];
char s[MX];
void msort(int x, int d, int le, int ri) {
  if (v[x][d].empty()) v[x][d]=v[x][0];
  if (le<ri) {
    int mid=(le+ri)/2;
    msort(x,d+1,le,mid);
    msort(x,d+1,mid+1,ri);
    for (int i=le, j=mid+1, k=le; k<=ri; k++) if (i>mid || (i<=mid && j<=ri && v[x][d+1][i]>v[x][d+1][j]))
      v[x][d][k]=v[x][d+1][j++]; else v[x][d][k]=v[x][d+1][i++];
  }
  /*printf("%d %d %d..%d: [",x,d,le,ri);
  for (int i=le; i<=ri; i++) printf("%d,",v[x][d][i]);
  puts("]");*/
}
int fnd(int x, int d, int le, int ri, int lft, int rgh, int val) {
  if (le==lft && ri==rgh) {
    if (x==0) {
      if (v[x][d][le]>val) return 0;
      while (le<ri) {
        int mid=(le+ri)/2+1;
        if (v[x][d][mid]>val) ri=mid-1; else le=mid;
      }
      return le-lft+1;
    } else {
      if (v[x][d][ri]<val) return 0;
      while (le<ri) {
        int mid=(le+ri)/2;
        if (v[x][d][mid]>=val) ri=mid; else le=mid+1;
      }
      return rgh-ri+1;
    }
  }
  int mid=(le+ri)/2,res=0;
  if (lft<=mid) res+=fnd(x,d+1,le,mid,lft,min(mid,rgh),val);
  if (rgh>mid) res+=fnd(x,d+1,mid+1,ri,max(mid+1,lft),rgh,val);
  return res;
}
int main() {
  scanf("%d%d",&n,&m);
  scanf("%s",s);
  for (i=1; i<n; i++) if (s[i]=='1' && s[i-1]=='1') {
    b[i]=b[i-1]+1;
    pos.push_back(i);
    v[0][0].push_back(b[i]);
  } else if (s[i]=='0' && s[i-1]=='0') {
    b[i]=b[i-1]-1;
    neg.push_back(i);
    v[1][0].push_back(b[i]);
  } else b[i]=b[i-1];
  sz[0]=v[0][0].size();
  sz[1]=v[1][0].size();
  if (!v[0][0].empty()) msort(0,0,0,sz[0]-1);
  if (!v[1][0].empty()) msort(1,0,0,sz[1]-1);
  while (m--) {
    scanf("%d%d",&x,&y);
    --x; --y;
    int res=abs(b[y]-b[x])+1;
    if (!pos.empty()) {
      int lft=upper_bound(pos.begin(),pos.end(),x)-pos.begin();
      int rgh=upper_bound(pos.begin(),pos.end(),y)-pos.begin();
      if (lft<rgh) res+=fnd(0,0,0,sz[0]-1,lft,rgh-1,b[x]);
    }
    if (!neg.empty()) {
      int lft=upper_bound(neg.begin(),neg.end(),x)-neg.begin();
      int rgh=upper_bound(neg.begin(),neg.end(),y)-neg.begin();
      if (lft<rgh) res+=fnd(1,0,0,sz[1]-1,lft,rgh-1,b[x]);
    }
    printf("%d\n",res);
  }
  return 0;
}