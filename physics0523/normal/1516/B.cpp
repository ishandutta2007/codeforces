#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,v=0,w=1;
    cin >> n;
    vector<int> rx(n+1);
    for(int i=1;i<=n;i++){
      cin >> rx[i];
      rx[i]^=rx[i-1];
    }
    bool fl=false;
    for(int i=1;i<=n;i++){
      if((rx[i])==(rx[i]^rx[n])){fl=true;}
    }
    for(int i=1;i<=n;i++){
      for(int j=i+1;j<=n;j++){
        if(rx[i]==(rx[i]^rx[j])&&rx[i]==(rx[j]^rx[n])){fl=true;}
      }
    }
    if(fl){cout << "YES\n";}else{cout << "NO\n";}
  }
  return 0;
}