#include<bits/stdc++.h>
using namespace std;

int T, n, cnt[505000], els[505000], ans;
char s[505000];

void fuck(){
  {
    int now=0, fl=1;
    for (int i=1;i<=n;++i){
      now+=(s[i]=='('? 1: -1);
      if (now<0) fl=0;
    }
    if (fl){
      ++cnt[now];
      return;
    }
  }
  {
    int now=0, fl=1;
    for (int i=n;i>=1;--i){
      now+=(s[i]==')'? 1: -1);
      if (now<0) fl=0;
    }
    if (fl){
      ++els[now];
      return;
    }
  }
}

int main(){
  cin>>T;
  for (;T--;){
    scanf("%s",s+1); n=strlen(s+1);
    fuck();
  }
  ans=cnt[0]/2;
  for (int i=1;i<=5e5+5;++i) ans+=min(cnt[i],els[i]);
  cout<<ans<<endl;
}