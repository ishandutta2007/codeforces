#include <bits/stdc++.h>
using namespace std;
int n,q,i,pos,cnt;
char s[100100],c[5];
int main() {
  scanf("%d%d",&n,&q);
  scanf("%s",s);
  for (i=2; i<n; i++) if (s[i]=='c' && s[i-1]=='b' && s[i-2]=='a') ++cnt;
  while (q--) {
    scanf("%d",&pos);
    --pos;
    for (i=min(n-1,pos+2); i>=pos && i>=2; i--) if (s[i]=='c' && s[i-1]=='b' && s[i-2]=='a') --cnt;
    scanf("%s",c);
    s[pos]=c[0];
    for (i=min(n-1,pos+2); i>=pos && i>=2; i--) if (s[i]=='c' && s[i-1]=='b' && s[i-2]=='a') ++cnt;
    printf("%d\n",cnt);
  }
  return 0;
}