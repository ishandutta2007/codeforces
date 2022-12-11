#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,k,a,b;
  cin >> n >> k >> a >> b;
  int cnt = 0,last = 0;
  string ans;
  while(n--){
    cnt++;
    if(cnt>k){
      if(last==0){
        b--;
        last=1;
        cnt=1;
        ans+='B';
      }
      else{
        a--;
        last=0;
        cnt=1;
        ans+='G';
      }
    }
    else{
      if(a>b){
        ans+='G';
        a--;
        if(last==1)cnt=1;
        last=0;
      }
      else{
        ans+='B';
        b--;
        if(last==0)cnt=1;
        last=1;
      }
    }
    if(a<0 or b<0){
      cout << "NO\n";
      return 0;
    }
  }
  cout << ans;
  return 0;
}