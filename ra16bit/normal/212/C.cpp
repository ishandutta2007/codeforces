#include <stdio.h>
#include <string.h>
char s[111];
int n,i;
long long r,f[111][2];
void solve(int st) {
  for (i=st; i<=n+1; i++) {
    f[i][s[i]-'A']+=f[i-1][1];
    if (s[i]=='A' || s[i-1]=='B')  f[i][s[i]-'A']+=f[i-1][0];
    if (i<=n && s[i]=='B' && s[i+1]=='A') f[i+1][1]+=f[i-1][0]+f[i-1][1];
  }
}
int main() {
  scanf("%s",s);
  n=strlen(s);
  if (s[0]=='A' && s[n-1]=='B') {
    for (i=n-1; i>0; i--) s[i]=s[i-1];
    s[0]='B';
  }
  s[n]=s[0];
  s[n+1]=s[1];
  f[0][s[0]-'A']=1;
  solve(1);
  r=f[n][s[n]-'A'];
  if (s[0]=='B' && s[1]=='A') {
    memset(f,0,sizeof(f));
    f[1][1]=1;
    solve(2);
    r+=f[n+1][1];
  }
  printf("%I64d\n",r);
  return 0;
}