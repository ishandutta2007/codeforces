#include <stdio.h>
#include <string.h>
const int MX=200010,md=1000000007;
int n,m,q,i,j,tot,cnt,sum,w[MX],st[MX],l[11],r[11];
long long p[MX],cur;
char s[MX],t[MX];
int main() {
  for (p[0]=i=1; i<MX; i++) p[i]=(p[i-1]*i)%md;
  for (i=0; i<10; i++) { l[i]=10; r[i]=i; }
  scanf("%s",s);
  tot=strlen(s);
  scanf("%d",&q);
  for (i=1; i<=q; i++) {
    scanf("%s",t);
    m=strlen(t);
    w[i]=t[0]-'0';
    st[i]=tot;
    for (j=3; j<m; j++, tot++) s[tot]=t[j];
  }
  st[q+1]=tot;
  for (i=q; i>=0; i--) {
    cur=1; sum=0;
    for (j=st[i+1]-1; j>=st[i]; j--) {
      sum=(sum+r[s[j]-'0']*cur)%md;
      cur=(cur*l[s[j]-'0'])%md;
    }
    l[w[i]]=cur;
    r[w[i]]=sum;
  }
  printf("%d\n",r[0]);
  return 0;
}