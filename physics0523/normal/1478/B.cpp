#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int q,d;
    cin >> q >> d;
    vector<bool> fl(128,false);
    fl[0]=true;
    for(int i=1;i<128;i++){
      string s=to_string(i);
      bool isok=false;
      for(auto &nx : s){
        if(nx==('0'+d)){isok=true;}
      }
      if(!isok){continue;}
      for(int j=0;i+j<128;j++){
        if(fl[j]){fl[i+j]=true;}
      }
    }
    while(q>0){
      q--;
      int v;
      cin >> v;
      if(v>=128){cout << "YES\n";}
      else if(fl[v]){cout << "YES\n";}
      else{cout << "NO\n";}
    }
  }
  return 0;
}