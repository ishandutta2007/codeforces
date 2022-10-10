#include <bits/stdc++.h>
using namespace std;
int n,i,j,cur,cnt[44];
long long a[44][44],mx;
char s[100100];
int main() {
  scanf("%s",s);
  n=strlen(s);
  for (i=0; i<n; i++) {
    cur=s[i]-'a';
    for (j=0; j<26; j++) a[j][cur]+=cnt[j];
    ++cnt[cur];
  }
  for (i=0; i<26; i++) {
    mx=max(mx,1LL*cnt[i]);
    for (j=0; j<26; j++) mx=max(mx,a[i][j]);
  }
  printf("%lld\n",mx);
  return 0;
}