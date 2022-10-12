#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int q;
  cin >> q;
  while(q>0){
    q--;

    string s,t;
    cin >> s >> t;
    if(t=="a"){
      cout << "1\n";
      continue;
    }
    bool ain=false;
    for(auto &nx : t){if(nx=='a'){ain=true;}}
    if(ain){cout << "-1\n";continue;}

    int cnt=0;
    for(auto &nx : s){if(nx=='a'){cnt++;}}
    cout << (1ll<<cnt) << '\n';
  }
  return 0;
}