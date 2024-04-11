#include <bits/stdc++.h>
using namespace std;
int tt,n,i,js,jt,a[200200],cc,c[200200],fi[200200],cnt[5];
char s[200200],t[200200];
int main() {
  scanf("%d",&tt);
  while (tt--) {
    scanf("%d",&n);
    if (n==-1) return 0;
    a[1]=cc=1;
    fi[1]=1;
    if (n>1) {
      printf("Q %d",n/2);
      for (i=2; i<=n; i+=2) printf(" %d %d",i-1,i);
      puts("");
      fflush(stdout);
      scanf("%s",s);
      if (s[0]=='-') return 0;
      if (n>2) {
        printf("Q %d",(n-1)/2);
        for (i=3; i<=n; i+=2) printf(" %d %d",i-1,i);
        puts("");
        fflush(stdout);
        scanf("%s",t);
        if (t[0]=='-') return 0;
      }
//      fprintf(stderr, "n=%d\n",n);
      for (js=jt=0, i=2; i<=n; i++) if ((i&1)==0) {
//        fprintf(stderr, "s.. %d\n",i);
        if (s[js]=='0') {
          a[i]=++cc;
          fi[cc]=i;
        } else a[i]=a[i-1];
        js++;
      } else {
//        fprintf(stderr, "t.. %d\n",i);
        if (t[jt]=='0') {
//          fprintf(stderr, "t.. %d\n",i);
          a[i]=++cc;
          fi[cc]=i;
        } else a[i]=a[i-1];
        jt++;
      }
    }
    c[1]=1;
    c[2]=2;
    if (cc>2) {
        printf("Q %d",cc/4+(cc+1)/4);
        for (i=3; i<=cc; i+=4) {
          printf(" %d %d",fi[i-2],fi[i]);
          if (i+1<=cc) printf(" %d %d",fi[i-1],fi[i+1]);
        }
        puts("");
        fflush(stdout);
        scanf("%s",s);
        if (s[0]=='-') return 0;
//        fprintf(stderr, "cc=%d\n",cc);
        if (cc>4) {
          printf("Q %d",(cc-1)/4+(cc-2)/4);
          for (i=5; i<=cc; i+=4) {
            printf(" %d %d",fi[i-2],fi[i]);
            if (i+1<=cc) printf(" %d %d",fi[i-1],fi[i+1]);
          }
          puts("");
          fflush(stdout);
          scanf("%s",t);
          if (t[0]=='-') return 0;
        }
        for (jt=js=0, i=3; i<=cc; i++) if (i%4==0 || i%4==3) {
          if (s[js]=='1') c[i]=c[i-2]; else c[i]=1+2+3-c[i-2]-c[i-1];
          js++;
        } else {
          if (t[jt]=='1') c[i]=c[i-2]; else c[i]=1+2+3-c[i-2]-c[i-1];
          jt++;
        }
    }
    for (i=1; i<=3; i++) cnt[i]=0;
    for (i=1; i<=n; i++) cnt[c[a[i]]]++;
    printf("A %d %d %d\n",cnt[1],cnt[2],cnt[3]);
    for (i=1; i<=n; i++) if (c[a[i]]==1) printf("%d ",i); puts("");
    for (i=1; i<=n; i++) if (c[a[i]]==2) printf("%d ",i); puts("");
    for (i=1; i<=n; i++) if (c[a[i]]==3) printf("%d ",i); puts("");
    fflush(stdout);
  }
  return 0;
}