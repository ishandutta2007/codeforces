#include <bits/stdc++.h>
using namespace std;
const int MX=1100100;
int n,m,A,B,MSK,msk,ii,i,j,cur,lst,le[28],ri[28],cnt[28],k[28],lft[MX],rgh[MX],c[MX],f[MX];
char s[5005],rev[22];
bool cmp(int i, int j) { return le[rev[i]-'a']<le[rev[j]-'a']; }
int main() {
  scanf("%d%d%d",&n,&A,&B);
  scanf("%s",s+1);
  for (i=1; i<=n; i++) {
    if (le[s[i]-'a']==0) le[s[i]-'a']=i;
    ri[s[i]-'a']=i;
    ++cnt[s[i]-'a'];
  }
  for (i=0; i<26; i++) if (cnt[i]>0) {
    msk=(1<<m);
    k[m]=m;
    c[msk]=cnt[i];
    lft[msk]=le[i];
    rgh[msk]=ri[i];
    rev[m++]=i+'a';
  }
  sort(k,k+m,cmp);
  MSK=((1<<m)-1);
  for (i=1; i<=MSK; i++) {
    msk=(i&(i-1));
    if (msk==0) {
      f[i]=((A*(rgh[i]-lft[i]+1)>c[i]*B)?i:MSK);
      continue;
    }
    c[i]=c[msk]+c[msk^i];
    lft[i]=min(lft[msk],lft[msk^i]);
    rgh[i]=max(rgh[msk],rgh[msk^i]);
    //for (j=msk; j>0; j=((j-1)&msk)) f[i]|=(f[j]&f[i^j]);
    for (cur=j=0; j<m; j++) if ((i>>k[j])&1) {
      cur|=(1<<k[j]);
      if (cur!=i) f[i]|=(f[cur]&f[i^cur]);
    }
    if (A*(rgh[i]-lft[i]+1)>c[i]*B) continue;
    for (lst=0; lst<m; lst++) if ((i>>lst)&1) {
      ii=(i^(1<<lst));
      if ((f[ii]>>lst)&1) f[i]|=(1<<lst); else for (cur=j=0; j<m; j++) if ((ii>>k[j])&1) {
        cur|=(1<<k[j]);
        if (cur!=ii && (f[cur]&f[ii^cur]&(1<<lst))) {
          f[i]|=(1<<lst);
          break;
        }
      }
    }
    if (f[i]>0) f[i]|=(MSK^i);
  }
  for (j=i=0; i<m; i++) if ((f[MSK]>>i)&1) ++j;
  printf("%d",j);
  for (i=0; i<m; i++) if ((f[MSK]>>i)&1) printf(" %c",rev[i]);
  return 0;
}