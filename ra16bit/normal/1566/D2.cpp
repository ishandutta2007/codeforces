#include <bits/stdc++.h>
using namespace std;
const int MX=303*303;
int t,n,m,num,i,j,k,st,r,a[MX],b[MX],ans[MX];
unordered_map<int,vector<int>> pos;
unordered_map<int,int> ptr;
bool cmp(int i, int j) {
  int x=i/m;
  int y=j/m;
  if (x!=y) return (x<y);
  return i>j;
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    num=n*m;
    for (i=0; i<num; i++) {
      scanf("%d",&a[i]);
      b[i]=a[i];
    }
    sort(b,b+num);
    pos.clear();
    ptr.clear();
    for (i=0; i<num; i++) pos[b[i]].push_back(i);
    for (auto it=pos.begin(); it!=pos.end(); it++) {
      sort(it->second.begin(),it->second.end(),cmp);
      ptr[it->first]=0;
    }
    for (i=0; i<num; i++) {
      auto it=pos.find(a[i]);
      auto jt=ptr.find(a[i]);
      ans[it->second[jt->second]]=i;
      ++(jt->second);
    }
    for (r=i=0; i<n; i++) {
      st=i*m;
      for (j=1; j<m; j++) for (k=0; k<j; k++) if (ans[st+j]>ans[st+k]) ++r;
    }
    printf("%d\n",r);
  }
  return 0;
}