#include <bits/stdc++.h>
using namespace std;
const int MX=4444;
int t,n,m,i,j,a[MX],c[2],cnt[2];
char s[MX],z[MX];
vector<int> r;
int main() {
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  scanf("%d",&t);
  while (t--) {
    scanf("%s",s);
    scanf("%s",z);
    n=strlen(s);
    cnt[0]=cnt[1]=0;
    for (i=1; i<n; i+=2) {
      if (s[i]==s[i-1]) ++cnt[s[i]-'0'];
      if (z[i]==z[i-1]) --cnt[z[i]-'0'];
    }
    if (cnt[0] || cnt[1]) { puts("-1"); continue; }
    r.clear();
    for (i=n-1; i>=1; i-=2) {
      if (s[i]==z[i] && s[i-1]==z[i-1]) continue;
      if (s[0]==z[i] && s[1]==z[i-1]) {
        r.push_back(i+1);
        reverse(s,s+i+1);
        continue;
      }
      cnt[0]=cnt[1]=0;
      for (j=1; j<i; j+=2) if (s[j]!=s[j-1]) ++cnt[s[j]-'0'];
      bool good=(i==1 || z[i-2]==z[i-3]);
      c[0]=c[1]=m=0;
      for (j=1; j<i; j+=2) {
        if (s[j]!=s[j-1]) --cnt[s[j]-'0'];
        if (s[j]==z[i] && s[j-1]==z[i-1] && (good || cnt[z[i-3]-'0']+c[z[i-2]-'0']>0))
        if (s[j]!=s[j-1]) ++c[s[j]-'0'];
      }
      if (m>0) {
        j=a[rng()%m];
        r.push_back(j+1);
        reverse(s,s+j+1);
        r.push_back(i+1);
        reverse(s,s+i+1);
        continue;
      }
      m=0;
      for (j=1; j<i; j+=2) if (s[j]==z[i] && s[j-1]==z[i-1]) a[m++]=j;
      if (m>0) {
        j=a[rng()%m];
        r.push_back(j+1);
        reverse(s,s+j+1);
        r.push_back(i+1);
        reverse(s,s+i+1);
      } else {
        for (j=1; j<=i; j+=2) if (s[j]!=s[j-1]) a[m++]=j;
        j=a[rng()%m];
        r.push_back(j+1);
        reverse(s,s+j+1);
        r.push_back(2);
        swap(s[0],s[1]);
        r.push_back(i+1);
        reverse(s,s+i+1);
      }
    }
    printf("%d\n",int(r.size()));
    for (i=0; i<r.size(); i++) printf("%d%c",r[i],(i+1==r.size())?'\n':' ');
  }
  return 0;
}