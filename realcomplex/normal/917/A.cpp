#include <bits/stdc++.h>

using namespace std;

int main(){
  string a;
  cin >> a;
  int n = a.size();
  int cnt = 0,ans=0,q,er;
  for(int i = 0;i<n;i++){
    cnt=0,q=0,er=0;
    for(int j = i;j<n;j++){
      if(a[j]=='('){
        cnt++;
      }
      else if(a[j]==')'){
        cnt--;
        if(cnt==-1){
          if(q>0)q--,cnt=0;
          else if(er>0)er--,cnt=1;
          else break;
        }
      }
      else if(a[j]=='?'){
        if(cnt>0)cnt--,er++;
        else q++;
      }
      if((j-i)%2==1 and cnt==0){
        ans++;
      }
    } 
  }
  cout << ans << "\n";
  return 0;
}