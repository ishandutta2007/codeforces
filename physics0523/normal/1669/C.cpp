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
    vector<int> f(2,0);
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      if(v%2){f[i%2]|=1;}
      else{f[i%2]|=2;}
    }
    if(f[0]==3 || f[1]==3){cout << "NO\n";}
    else{cout << "YES\n";}
  }
  return 0;
}