#include <bits/stdc++.h>

using namespace std;
#define fi first
#define se second

map<string,string>handle;

int main(){
  ios_base::sync_with_stdio(NULL);
  int q;
  cin >> q;
  string old,ne;
  for(int i = 0;i<q;i++){
    cin >> old >> ne;
    if(handle[old].empty())handle[ne]=old;
    else{
      handle[ne]=handle[old];
      handle.erase(old);
    }
  }
  cout << handle.size()/2 << "\n";
  for(auto x:  handle){
    if(!x.se.empty())cout << x.se << " " << x.fi << "\n";
  }
  return 0;
}