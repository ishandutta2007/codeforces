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
    int v;
    for(int i=0;i<n;i++){
      int w;
      cin >> w;
      if(i==0){v=w;}
      else{v&=w;}
    }
    cout << v << '\n';
  }
  return 0;
}