#include <bits/stdc++.h>
using namespace std;
int n,i,j,e,len,mid,cnt1,cnt2,cur,prv,k[111*111*2],cnt[28][111];
char st[111],r[111];
string s[111*111*2];
bool cmp(int i, int j) {
  if (s[i].length()!=s[j].length()) return s[i].length()<s[j].length();
  return s[i]<s[j];
}
int main() {
  scanf("%d",&n);
  if (n<=3) {
    for (i=1; i<=n; i++) {
      printf("? %d %d\n",i,i);
      fflush(stdout);
      scanf("%s",st); s[i]=st;
    }
    printf("! ");
    for (i=1; i<=n; i++) printf("%c",s[i][0]);
    puts("");
    fflush(stdout);
    return 0;
  }
  mid=(n+1)/2;
  cnt1=(mid*(mid+1))/2;
  cnt2=(mid*(mid-1))/2;
  printf("? %d %d\n",1,mid);
  fflush(stdout);
  for (i=0; i<cnt1; i++) {
    scanf("%s",st); s[i]=st;
    sort(s[i].begin(),s[i].end());
    k[i]=i;
  }
  printf("? %d %d\n",2,mid);
  fflush(stdout);
  for (i=cnt1; i<cnt1+cnt2; i++) {
    scanf("%s",st); s[i]=st;
    sort(s[i].begin(),s[i].end());
    k[i]=i;
  }
  sort(k,k+cnt1,cmp);
  sort(k+cnt1,k+cnt1+cnt2,cmp);
  len=0;
  for (i=j=0; i<cnt1; i++, j++) for (; i<cnt1 && (j>=cnt2 || s[k[i]]!=s[k[cnt1+j]]); i++) {
    cur=k[i];
    for (e=0; e<len; e++) if (s[prv][e]!=s[cur][e]) break;
    r[len++]=s[cur][e];
    prv=cur;
  }
  printf("? %d %d\n",1,n);
  fflush(stdout);
  cnt1=(n*(n+1))/2;
  for (i=0; i<cnt1; i++) {
    scanf("%s",st); s[i]=st;
    len=s[i].length();
    for (j=0; j<len; j++) cnt[s[i][j]-'a'][len]++;
  }
  for (i=1; n-i>=mid; i++) {
    for (j=0; j<26; j++) {
      cur=cnt[j][i]-(cnt[j][i+1]-cnt[j][i])*i;
      if (r[i-1]==j+'a') cur-=i;
      for (e=1; e<i; e++) {
        if (r[e-1]==j+'a') cur-=e;
        if (r[n-e]==j+'a') cur-=e;
      }
      if (cur>0) break;
    }
    r[n-i]=j+'a';
  }
  printf("! ");
  puts(r);
  fflush(stdout);
  return 0;
}