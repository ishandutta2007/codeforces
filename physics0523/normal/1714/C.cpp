#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int s;
    cin >> s;
    int res=1e9;
    for(int i=0;i<(1<<9);i++){
      int cur=0,sum=0;
      for(int j=0;j<9;j++){
        if(i&(1<<j)){
          cur*=10;
          cur+=(j+1);
          sum+=(j+1);
        }
      }
      if(sum==s){res=min(res,cur);}
    }
    cout << res << "\n";
  }
  return 0;
}