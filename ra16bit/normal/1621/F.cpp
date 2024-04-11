#include <bits/stdc++.h>
using namespace std;
const int MX=200200;
int t,n,a,b,c,i,j;
long long cnt[2],z,cz,sz,res;
char s[MX];
vector<int> all;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d%d%d",&n,&a,&b,&c);
    scanf("%s",s);
    cnt[0]=cnt[1]=0;
    all.clear();
    for (z=i=0; i<n; i=j) {
      for (j=i; j<n && s[i]==s[j]; j++);
      cnt[s[i]-'0']+=j-i-1;
      if (s[i]=='0') {
        ++z;
        if (i>0 && j<n) all.push_back(j-i-1);
      }
    }
    if (cnt[0]>=cnt[1]) {
      sz=min(cnt[0],cnt[1]+1);
      cz=cnt[1];
      res=cnt[1]*b+sz*a;
      if (c<b) {
        sort(all.begin(),all.end());
        for (j=0; j<all.size(); j++) {
          cz-=all[j];
          if (cz<0) break;
          res+=b-c;
        }
      }
    } else if (c<b) {
      res=cnt[0]*a+(cnt[0]+1)*b+min(z,n-z-cnt[0]-cnt[0]-2)*(b-c);
    } else {
      res=cnt[0]*a+(cnt[0]+1)*b;
    }
    printf("%lld\n",res);
  }
  return 0;
}