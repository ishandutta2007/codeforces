#include<bits/stdc++.h>

using namespace std;

bool jud(int x,int y,int z){
  if(y==z && x%2==0){return true;}
  if(x==y+z){return true;}
  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    vector<int> l(3);
    cin >> l[0] >> l[1] >> l[2];
    if(jud(l[0],l[1],l[2]) || jud(l[1],l[2],l[0]) || jud(l[2],l[0],l[1])){
      cout << "YES\n";
    }
    else{cout << "NO\n";}
  }
  return 0;
}