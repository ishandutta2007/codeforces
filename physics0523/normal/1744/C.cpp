#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;

    int n;
    string tg,s;
    cin >> n >> tg >> s;
    int res=0,cur=-1e9;
    for(int i=0;i<4*n;i++){
      if(s[i%n]==tg[0]){cur=max(cur,0);}

      if(s[i%n]=='g'){
        res=max(res,cur);
        cur=-1e9;
      }
      else{cur++;}
    }
    cout << res << "\n";
  }
  return 0;
}