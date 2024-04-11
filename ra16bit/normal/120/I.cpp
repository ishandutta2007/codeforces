#include <stdio.h>
#include <string.h>
const int mask[10]={119,18,93,91,58,107,111,82,127,123};
int n,i,j,l,r,d,bc[128],a[10][10];
char s[200100],t[200100];
void forwards(int i) {
  for (; i<n; i++) for (int j='0'; j<='9'; j++) if (l+bc[mask[j-'0']]+r>d) {
    s[i]=j;
    l+=bc[mask[j-'0']];
    r-=7;
    break;
  }
}
void forwardt(int i) {
  for (; i<n; i++) for (int j='0'; j<='9'; j++) if (l+a[s[i]-'0'][j-'0']+r>d) {
    t[i]=j;
    l+=a[s[i]-'0'][j-'0'];
    if (i<n-1) r-=bc[mask[s[i+1]-'0']];
    break;
  }
}
int main() {
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  for (i=1; i<128; i++) bc[i]=bc[i>>1]+(i&1);
  for (i=0; i<10; i++) for (j=0; j<10; j++) a[i][j]=bc[mask[i]&mask[j]];
  scanf("%s",s); n=strlen(s); n/=2;
  for (i=0; i<n; i++) {
    t[i]=s[n+i];
    d+=a[s[i]-'0'][t[i]-'0'];
  }
  for (l=d, i=n-1; i>=0; i--) {
    l-=a[s[i]-'0'][t[i]-'0'];
    for (j=t[i]+1; j<='9'; j++) if (l+a[s[i]-'0'][j-'0']+r>d) {
      t[i]=j;
      l+=a[s[i]-'0'][j-'0'];
      if (i<n-1) r-=bc[mask[s[i+1]-'0']];
      forwardt(i+1);
      break;
    }
    if (j<='9') break; else r+=bc[mask[s[i]-'0']];
  }
  if (i<0) {
    for (l=r=i=0; i<n; i++) l+=bc[mask[s[i]-'0']];
    for (i=n-1; i>=0; i--) {
      l-=bc[mask[s[i]-'0']];
      for (j=s[i]+1; j<='9'; j++) if (l+bc[mask[j-'0']]+r>d) {
        s[i]=j;
        l+=bc[mask[j-'0']];
        r-=7;
        forwards(i+1);
        for (l=r=0, i=1; i<n; i++) r+=bc[mask[s[i]-'0']];
        forwardt(0);
        break;
      }
      if (j<='9') break; else r+=7;
    }
    if (i<0) { puts("-1"); return 0; }
  }
  for (i=0; i<n; i++) s[n+i]=t[i];
  puts(s);
  return 0;
}