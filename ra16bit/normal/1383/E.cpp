#include <bits/stdc++.h>
using namespace std;
const int md=1000000007,MX=1000100;
int n,m,i,lft,cur,sum,pos,a[MX];
long long rgh;
char s[MX];
bool was;
int main() {
  scanf("%s",s);
  n=strlen(s);
  for (lft=rgh=-1, i=0; i<n; i++) if (s[i]=='1') {
    was=true;
    rgh=i;
  } else if (!was) lft=i;
  if (!was) { printf("%d\n",n); return 0; }
  a[0]=sum=1;
  for (i=lft+1; i<=rgh; i++) if (s[i]=='0') {
    ++pos;
    sum=(sum+md-a[pos])%md;
    a[pos]=cur;
    sum=(sum+a[pos])%md;
  } else {
    cur=(cur+sum)%md;
    pos=0;
  }
  cur=(cur*(lft+2LL))%md;
  cur=(cur*(n-rgh))%md;
  printf("%d\n",cur);
  return 0;
}