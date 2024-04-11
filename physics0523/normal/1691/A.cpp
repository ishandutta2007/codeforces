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
    int p=0,q=0;
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      if(v%2){p++;}else{q++;}
    }
    cout << min(p,q) << '\n';
  }
}