#include <bits/stdc++.h>
using namespace std;
char s[5050];
int n,i,cnt[277];
int main() {
  scanf("%s",s);
  n=strlen(s);
  for (i=0; i<n; i++) {
    if (s[i]<'a' || s[i]>'c') { puts("NO"); return 0; }
    cnt[s[i]-'a']++;
  }
  for (i=1; i<n; i++) if (s[i]<s[i-1]) { puts("NO"); return 0; }
  if (cnt[0]==0 || cnt[1]==0 || (cnt[2]!=cnt[0] && cnt[2]!=cnt[1])) { puts("NO"); return 0; }
  puts("YES");
  return 0;
}