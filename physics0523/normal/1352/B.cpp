#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    vector<int> res;
    int tg;
    bool fl=true;
    if(n%2==0 && m%2==0){tg=1;}
    if(n%2==0 && m%2==1){tg=2;}
    if(n%2==1 && m%2==0){fl=false;}
    if(n%2==1 && m%2==1){tg=1;}
    for(int i=0;i<m;i++){
      if(i==m-1){res.push_back(n);break;}
      res.push_back(tg);
      n-=tg;
      if(n<=0){fl=false;}
    }
    if(fl){
      cout << "YES\n";
      for(int i=0;i<m;i++){
        if(i){cout << ' ';}
        cout << res[i];
      }cout << '\n';
    }
    else{cout << "NO\n";}
  }
  return 0;
}