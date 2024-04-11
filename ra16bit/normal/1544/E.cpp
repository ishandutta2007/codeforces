#include <bits/stdc++.h>
using namespace std;
int t,i,j,fi,se,one,n,cnt[26];
char s[100100];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%s",s);
    n=strlen(s);
    for (i=0; i<26; i++) cnt[i]=0;
    for (i=0; i<n; i++) ++cnt[s[i]-'a'];
    for (fi=-1, one=-1, i=0; i<26; i++) if (cnt[i]==n) {
      puts(s);
      break;
    } else {
      if (cnt[i]>0 && fi==-1) fi=i;
      if (cnt[i]==1 && one==-1) one=i;
    }
    if (i<26) continue;
    if (one!=-1) {
      putchar('a'+one);
      --cnt[one];
      for (i=0; i<26; i++) for (j=0; j<cnt[i]; j++) putchar('a'+i);
      putchar('\n');
      continue;
    }
    cnt[fi]-=2;
    if (cnt[fi]<=(n-2)/2) {
      putchar('a'+fi);
      putchar('a'+fi);
      for (i=2; i<n; i++) for (j=fi+1-int(i&1); j<26; j++) if (cnt[j]>0) {
        putchar('a'+j);
        --cnt[j];
        break;
      }
      putchar('\n');
      continue;
    }
    cnt[fi]+=2;
    for (se=fi+1; se<26; se++) if (cnt[se]>0) break;
    if (cnt[fi]+cnt[se]==n) {
      putchar('a'+fi); --cnt[fi];
      for (j=0; j<cnt[se]; j++) putchar('a'+se);
      for (j=0; j<cnt[fi]; j++) putchar('a'+fi);
      putchar('\n');
      continue;
    }
    for (i=se+1; i<26; i++) if (cnt[i]>0) break;
    putchar('a'+fi); --cnt[fi];
    putchar('a'+se); --cnt[se];
    for (j=0; j<cnt[fi]; j++) putchar('a'+fi);
    putchar('a'+i); --cnt[i];
    for (j=0; j<cnt[se]; j++) putchar('a'+se);
    for (i=se+1; i<26; i++) for (j=0; j<cnt[i]; j++) putchar('a'+i);
    putchar('\n');
  }
  return 0;
}