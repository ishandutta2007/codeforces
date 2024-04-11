#include <bits/stdc++.h>
using namespace std;
int n,t,cur,z,cnt,x,i;
char s[777];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%s",s);
    n=strlen(s);
    for (z=cnt=x=i=0; i<n; i++) {
      cur=s[i]-'0';
      x+=cur;
      if (cur%2==0) cnt++;
      if (cur==0) z++;
    }
    if (x==0 || (x%3==0 && z>0 && cnt>1)) puts("red"); else puts("cyan");
  }
  return 0;
}