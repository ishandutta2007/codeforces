#include <bits/stdc++.h>
using namespace std;
int t,n,i,j,z,a[200200],cnt[14],p[14];
char s[200200],r[200200],prv;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    scanf("%s",s);
    for (p[0]=i=0; i<=10; i++) cnt[i]=0;
    for (i=0; i<n; i++) cnt[s[i]-'0'+1]++;
    for (i=1; i<=10; i++) {
      cnt[i]+=cnt[i-1];
      p[i]=cnt[i];
    }
    for (i=0; i<n; i++) {
      a[p[s[i]-'0']++]=i;
      r[i]='2';
    }
    for (r[n]=i=0; i<10; i++) if (cnt[i]>0 && cnt[i]<cnt[i+1] && a[cnt[i]]<a[cnt[i]-1]) {
      z=a[cnt[i]-1];
      for (j=cnt[i]; j<cnt[i+1]; j++) if (a[j]>z) r[a[j]]='1';
      break;
    } else for (j=cnt[i]; j<cnt[i+1]; j++) r[a[j]]='1';
    prv='0';
    for (i=0; i<n; i++) if (r[i]=='2') {
      if (s[i]<prv) break;
      prv=s[i];
    }
    puts((i<n)?"-":r);
  }
  return 0;
}