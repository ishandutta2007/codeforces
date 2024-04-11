#include<bits/stdc++.h>
using namespace std;
 
char s[1001000],ss[1001000];
int n,m,fai[1001000],cnt[2333];
 
int main(){
  scanf("%s",s+1);n=strlen(s+1);
  for (int i=1;i<=n;++i) ++cnt[s[i]];
  
  scanf("%s",ss+1);m=strlen(ss+1);
  fai[fai[1]=0]=-1;
  int pos=0;
  for (int i=2;i<=m;i++){
    while (pos>=0&&ss[pos+1]!=ss[i]) pos=fai[pos];
    fai[i]=++pos;
  }
  int mxp=fai[m];

  for (int i=1;i<=m;++i)
    if (cnt[ss[i]]){
      putchar(ss[i]);
      --cnt[ss[i]];
    }
  for (int fl=1;fl;){
    for (int i=mxp+1;i<=m;++i)
      if (cnt[ss[i]]){
        putchar(ss[i]);
        --cnt[ss[i]];
      }else{
        fl=0;
      }
  }
  for (int t='0';t<='1';++t)
    for (;cnt[t];){
      putchar(t);
      cnt[t]--;
    }
  puts("");
}