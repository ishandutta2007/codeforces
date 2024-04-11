#include <bits/stdc++.h>
using namespace std;
const int MX=100100;
int n,m,i,rgh,ch[MX],sr[MX];
long long r;
char s[MX];
int main() {
  scanf("%d%d",&n,&m);
  scanf("%s",s);
  sr[n-1]=1;
  for (i=n-2; i>=0; i--) sr[i]=sr[i+1]+int(s[i]!=s[i+1]);
  ch[n-2]=n-2;
  ch[n-1]=n-1;
  for (i=n-1; i>=0; i--) ch[i]=(s[i]==s[i+2])?ch[i+2]:i;
  r=m-1;
  for (i=0; i<n-1; i++) {
    r+=(m-1LL)*sr[i+1];
    if (s[i]!=s[i+1]) {
      r+=(m-1LL)*(n-i);
      rgh=min(ch[i],ch[i+1])+1;
      r-=rgh-i;
    }
  }
  printf("%I64d\n",r);
  return 0;
}