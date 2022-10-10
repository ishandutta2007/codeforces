#include <bits/stdc++.h>
using namespace std;
int tt,n,i,j,k,r,cnt[26];
char s[111],t[111];
int main() {
  scanf("%d",&tt);
  while (tt--) {
    scanf("%d",&n);
    scanf("%s",s);
    scanf("%s",t);
    for (i=0; i<26; i++) cnt[i]=0;
    for (i=0; i<n; i++) {
      cnt[s[i]-'a']++;
      cnt[t[i]-'a']--;
    }
    for (i=0; i<26; i++) if (cnt[i]!=0) break;
    if (i<26) { puts("-1"); continue; }
    for (r=i=0; i<n; i++) {
      for (j=i, k=0; j<n; j++) {
        while (k<n && s[k]!=t[j]) k++;
        if (k>=n) break; else k++;
      }
      r=max(r,j-i);
    }
    printf("%d\n",n-r);
  }
  return 0;
}