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
    vector<int> a(n);
    for(auto &nx : a){cin >> nx;}

    vector<int> res;
    int cur=0;
    while(1){
      int mx=cur,tg=-1;
      for(int i=0;i<n;i++){
        if(a[i]==-1){continue;}
        if((cur|a[i])>mx){
          tg=i;
          mx=(cur|a[i]);
        }
      }
      if(tg==-1){break;}
      cur|=a[tg];
      res.push_back(a[tg]);
      a[tg]=-1;
    }
    for(auto &nx : a){
      if(nx>=0){res.push_back(nx);}
    }

    for(int i=0;i<n;i++){
      if(i){cout << " ";}
      cout << res[i];
    }cout << "\n";
  }
  return 0;
}