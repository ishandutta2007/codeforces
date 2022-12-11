#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll leftMulti[5005];
ll leftAdd[5005];
ll rightMulti[5005];
ll rightAdd[5005];

void init(){
  for(int i = 0;i<5005;i++)
    leftMulti[i]=1,rightMulti[i]=1;
} 

int main(){
  init();
  string s;
  cin >> s;
  ll last;
  for(int i = 0;i<s.size();i+=2){
    for(int j = i-2;j>=0;j-=2){
      if(s[j+1]=='*'){
        leftMulti[i]*=s[j]-48;
      }
      else{
        last=s[j]-48;
        for(int x = j-2;x>=0;x-=2){
          if(s[x+1]=='+'){
            leftAdd[i]+=last;
            last=s[x]-48;
          }
          else last*=s[x]-48;
        }
        leftAdd[i]+=last;
        break;
      }
    }
    for(int j = i+2;j<s.size();j+=2){
      if(s[j-1]=='*'){
        rightMulti[i]*=s[j]-48;
      }
      else{
        last=s[j]-48;
        for(int x = j+2;x<s.size();x+=2){
          if(s[x-1]=='+'){
            rightAdd[i]+=last;
            last=s[x]-48;
          } 
          else last*=s[x]-48;
        }
        rightAdd[i]+=last;
        break;
      }
    }
  }
  ll ans = 0;
  ll cur = 0;
  for(int i = 0;i<s.size();i+=2){
    last=s[i]-48;
    cur=0;
    ans=max(ans,(last*leftMulti[i]*rightMulti[i])+leftAdd[i]+rightAdd[i]);
    for(int j = i+2;j<s.size();j+=2){
      if(s[j-1]=='+'){
        cur+=last;
        last=s[j]-48;
      }
      else last*=s[j]-48;
      ans=max(ans,((last+cur)*leftMulti[i]*rightMulti[j])+leftAdd[i]+rightAdd[j]);
    }
  }
  cout << ans << "\n";
  return 0;
}