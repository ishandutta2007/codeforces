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
    vector<int> a(n),res;
    for(int i=0;i<n;i++){cin >> a[i];}
    int g;
    for(int i=0;i<n;i++){
      int mx=-1,pos;
      for(int j=0;j<n;j++){
        if(a[j]==0){continue;}
        int at;
        if(i){at=gcd(g,a[j]);}
        else{at=a[j];}
        if(at>mx){mx=at;pos=j;}
      }
      res.push_back(a[pos]);
      if(i){g=gcd(g,a[pos]);}
      else{g=a[pos];}
      a[pos]=0;
    }
    for(int i=0;i<n;i++){
      if(i){cout << ' ';}
      cout << res[i];
    }cout << '\n';
  }
  return 0;
}