#include <bits/stdc++.h>
using namespace std;
const int MX=1000100;
int n,m,i,len,pos,cnt[2],a[MX],b[MX];
char s[MX];
bool bad;
void msort(int l, int r) {
  if (r-l<=1) return;
  int mid=(l+r)/2;
  msort(l,mid); if (bad) return;
  msort(mid,r); if (bad) return;
  int i=l,j=mid,k=l;
  while (i<mid && j<r) {
    if (pos>=n) { bad=true; return; }
    if (s[pos++]=='0') b[k++]=a[i++]; else b[k++]=a[j++];
  }
  while (i<mid) b[k++]=a[i++];
  while (j<r) b[k++]=a[j++];
  for (int p=l; p<r; p++) a[p]=b[p];
}
int main() {
  scanf("%s",s);
  n=strlen(s);
  for (i=n-1; i>=0; i--) {
    ++cnt[s[i]-'0'];
    if (cnt[0]>cnt[1]) {
      m=cnt[0]*2;
      pos=0;
      bad=false;
      msort(0,m);
      if (!bad && pos==n) break;
    }
    if (cnt[1]>cnt[0]) {
      m=cnt[1]*2;
      pos=0;
      bad=false;
      msort(0,m);
      if (!bad && pos==n) break;
    }
    if (cnt[0]>=cnt[1]) {
      m=cnt[0]*2+1;
      pos=0;
      bad=false;
      msort(0,m);
      if (!bad && pos==n) break;
    }
    if (cnt[1]>1 && cnt[1]>cnt[0]+1) {
      m=cnt[1]*2-1;
      pos=0;
      bad=false;
      msort(0,m);
      if (!bad && pos==n) break;
    }
  }
  printf("%d\n",m);
  for (i=0; i<m; i++) a[i]=i;
  pos=0;
  msort(0,m);
  for (i=0; i<m; i++) b[a[i]]=i;
  for (i=0; i<m; i++) printf("%d ",b[i]+1);
  return 0;
}