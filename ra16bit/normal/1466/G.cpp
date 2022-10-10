#include <bits/stdc++.h>
using namespace std;
const int MX=2000200,md=1000000007;
int t,num,n,q,mx,tot,ch,i,j,k,pos,it,r,len[100100],cnt[100100][26],p[2*MX],u[MX];
long long pw2[100100],o[100100],now;
char cur[2*MX],s[MX],T[100100];
bool stp;
long long pw(long long a, int b) {
  if (b==0) return 1LL;
  if (b&1) return (pw(a,b-1)*a)%md;
  long long x=pw(a,b/2);
  return (x*x)%md;
}
void kmp() {
  int k=0;
  for (int i=2; i<=tot; i++) {
    while (k>0 && cur[i]!=cur[k+1]) k=p[k];
    if (cur[i]==cur[k+1]) ++k;
    p[i]=k;
  }
}
int main() {
  for (pw2[0]=i=1; i<100100; i++) pw2[i]=(pw2[i-1]*2)%md;
  scanf("%d%d",&n,&q);
  scanf("%s",s+1);
  len[0]=strlen(s+1);
  scanf("%s",T+1);
  for (i=1; i<=n; i++) {
    len[i]=(len[i-1]*2+1)%md;
    if (!stp && len[i]+10<MX) {
      s[len[i-1]+1]=T[i];
      for (j=1; j<=len[i-1]; j++) s[len[i-1]+1+j]=s[j];
      mx=i;
      //printf("%d %d: ",i,len[i]);
      //puts(s+1);
    } else stp=true;
  }
  for (i=n; i>0; i--) {
    for (j=0; j<26; j++) cnt[i][j]=cnt[i+1][j];
    cnt[i][T[i]-'a']=(cnt[i][T[i]-'a']+pw2[n-i])%md;
    o[i]=pw(pw2[n-i],md-2);
  }
  scanf("%s",t);
  for (it=1; it<=q; it++) {
    r=0;
    scanf("%d",&k);
    scanf("%s",cur+1);
    num=strlen(cur+1);
    cur[num+1]='$';
    for (j=0; j<k && j<mx; j++) if (len[j]>=num) break; 
    if (len[j]<num) { puts("0"); continue; }
    tot=num+1+len[j];
    cur[tot+1]=0;
    for (i=1; i<=len[j]; i++) cur[num+1+i]=s[i];
    kmp();
    for (i=num+2; i<=tot; i++) if (p[i]==num) ++r;
    r=(r*pw2[k-j])%md;
    for (i=p[tot]; ; i=p[i]) {
      u[i]=it;
      if (i==0) break;
    }
    u[0]=it;
    reverse(cur+1,cur+num+1);
    reverse(cur+num+2,cur+tot+1);
    kmp();
    if (k>j) for (i=p[tot]; ; i=p[i]) {
      pos=num-i;
      if (pos>0 && u[pos-1]==it) {
        ch=cur[i+1]-'a';
        now=(cnt[j+1][ch]+md-cnt[k+1][ch])%md;
        if (now) r=(r+now*o[k])%md;
      }
      if (i==0) break;
    }
    printf("%d\n",r);
  }
  return 0;
}