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
    int z=0,o=0;
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      if(v==0){z++;}
      if(v==1){o++;}
    }
    if(o==0){cout << "0\n";}
    else{cout << (1ll<<z)*((long long)o) << '\n';}
  }
  return 0;
}