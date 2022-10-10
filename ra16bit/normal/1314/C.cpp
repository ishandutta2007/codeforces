#include <bits/stdc++.h>
using namespace std;
const long long MXZ=2000000000000000000LL;
int n,m,len,le,ri,h,i,j,nxt,lft,rgh,f[1010][1010],k[1010],sum;
long long dp[1010][1010],cnt;
char s[1010];
bool compare(int lx, int rx, int ly, int ry) {
  int cx=lx+f[lx][ly],cy=ly+f[lx][ly];
  if (cx>rx) {
    if (cy>ry) return rx-lx>ry-ly;
    return false;
  }
  if (cy>ry) return true;
  return s[cx]>s[cy];
}
bool cmp(int i, int j) {
  return compare(i,n-1,j,n-1);
}
void findsubstr(int h) {
  int cur=0,i;
  for (i=0; i<n; i++) {
    int nxt=cur+n-k[i]-(i+1<n?f[k[i+1]][k[i]]:0);
    if (nxt>=h) break; else cur=nxt;
  }
  lft=k[i]; rgh=n-h+cur;
}
int main() {
  scanf("%d%d%I64d",&n,&m,&cnt);
  scanf("%s",s);
  for (len=1; len<n; len++) for (i=n-1-len; i>=0; i--)
    f[i+len][i]=f[i][i+len]=(s[i]==s[i+len])?f[i+1][i+len+1]+1:0;
  for (i=0; i<n; i++) k[i]=i;
  sort(k,k+n,cmp);
  for (sum=i=0; i<n; i++) sum+=n-k[i]-(i>0?f[k[i-1]][k[i]]:0);
  le=1; ri=sum;
  /*for (i=1; i<=sum; i++) {
    findsubstr(i);
    printf("%d: ",i);
    for (j=lft; j<=rgh; j++) printf("%c",s[j]);
    puts("");
  }*/
  while (le<ri) {
    h=(le+ri)/2;
    findsubstr(h);
    memset(dp,0,sizeof(dp));
    //printf("%d..%d\n",le,ri);
    dp[0][0]=1;
    for (i=0; i<n; i++) {
      bool ge=false;
      for (j=i; j<n; j++) {
        if (s[j]<s[lft+j-i]) break;
        if (s[j]>s[lft+j-i] || (s[j]==s[lft+j-i] && j-i==rgh-lft)) {
          ge=true;
          break;
        }
      }
      nxt=j+1;
      for (j=0; j<=m; j++) if (dp[i][j]) {
        if (j>0) dp[i+1][j]=min(dp[i+1][j]+dp[i][j],MXZ);
        if (ge) dp[nxt][j+1]=min(dp[nxt][j+1]+dp[i][j],MXZ);
      }
    }
    if (dp[n][m]>=cnt) ri=h; else le=h+1;
  }
  findsubstr(ri);
  for (j=lft; j<=rgh; j++) printf("%c",s[j]); puts("");
  return 0;
}