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
    cin >> n;
    vector<int> p(n+1);
    for(int i=1;i<=n;i++){cin >> p[i];}
    //n+1 start
    if(p[1]==1){
      cout << n+1;
      for(int i=1;i<=n;i++){
        cout << ' ' << i;
      }cout << '\n';
    }
    else if(p[n]==0){
      for(int i=1;i<=n+1;i++){
        if(i-1){cout << ' ';}
        cout << i;
      }cout << '\n';
    }
    else{
      int tg=-1;
      for(int i=1;i<n;i++){
        if(p[i]==0 && p[i+1]==1){tg=i;break;}
      }
      if(tg==-1){cout << "-1\n";}
      else{
        bool fl=false;
        for(int i=1;i<=n;i++){
          if(fl){cout << ' ';}
          fl=true;
          cout << i;
          if(tg==i){
            if(fl){cout << ' ';}
            fl=true;
            cout << n+1;
          }
        }
        cout << '\n';
      }
    }
  }
  return 0;
}