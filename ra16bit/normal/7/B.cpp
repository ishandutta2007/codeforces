#include <cstdio>
#include <cstring>
using namespace std;
int n,m,i,j,a[110000],e[110000],b,c,q,x;
char s[110000];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<110000; i++) { a[i]=0; e[i]=-1; }
  for (i=0; i<n; i++) {
    scanf("%s",&s);
    if (strlen(s)==5 && s[0]=='a' && s[1]=='l' && s[2]=='l' && s[3]=='o' && s[4]=='c') {
      scanf("%d",&b);
      for (c=-1, q=j=0; j<m; j++) if (a[j]==0) {
        q++;
        if (q==b) { c=j-q+1; break; }
      } else q=0;
      if (c==-1) puts("NULL"); else {
        e[++x]=c; printf("%d\n",x);
        for (j=0; j<b; j++) a[c+j]=x;
      }
    } else if (strlen(s)==5 && s[0]=='e' && s[1]=='r' && s[2]=='a' && s[3]=='s' && s[4]=='e') {
      scanf("%d",&b);
      if (b<=0 || b>=110) puts("ILLEGAL_ERASE_ARGUMENT"); else {
        if (e[b]<0) puts("ILLEGAL_ERASE_ARGUMENT"); else for (j=e[b]; a[j]==b; j++) a[j]=0;
        e[b]=-1;
      }
    } else if (strlen(s)==10 && s[0]=='d' && s[1]=='e' && s[2]=='f' && s[3]=='r' && s[4]=='a' && s[5]=='g' && s[6]=='m' && s[7]=='e' && s[8]=='n' && s[9]=='t') {
      for (j=0; j<=x; j++) e[j]=-1;
      for (j=q=0; j<m; j++) if (a[j]!=0) {
        a[q]=a[j];
        if (e[a[q]]==-1) e[a[q]]=q;
        q++;
      }
      for (j=q; j<m; j++) a[j]=0;
    }
  }
  return 0;
}