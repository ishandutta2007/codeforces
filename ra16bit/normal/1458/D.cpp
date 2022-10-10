#include <bits/stdc++.h>
using namespace std;
const int MX=500500;
int t,n,i,cur,cnt[2*MX];
char s[MX];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%s",s);
    n=strlen(s);
    for (cur=MX-n; cur<=MX+n; cur++) cnt[cur]=0;
    for (cur=MX, i=0; i<n; i++) if (s[i]=='0') cnt[--cur]++; else cnt[cur++]++;
    for (cur=MX, i=0; cnt[cur-1]+cnt[cur]>0; i++)
      if (cnt[cur-1]>1 || (cnt[cur-1]==1 && cnt[cur]==0)) {
        s[i]='0'; cnt[--cur]--; 
      } else {
        s[i]='1'; cnt[cur++]--;
      }
    puts(s);
  }
  return 0;
}