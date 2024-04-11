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

    vector<int> res(n,-1);
    for(int i=0;i<n;i++){
      if(a[i]==0){res[i]=0;}
      else{break;}
    }
    for(int i=0;i<n;i++){
      if(res[i]==-1){res[i]=1;}
      int tg;
      if(res[i]==1){tg=a[i];}
      else{tg=a[i]+i;}
      if(tg<n){res[tg]=0;}
    }
    for(int i=0;i<n;i++){
      if(i){cout << ' ';}
      cout << res[i];
    }cout << '\n';
  }
  return 0;
}