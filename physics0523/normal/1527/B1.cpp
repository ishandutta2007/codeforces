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
    string s;
    cin >> n >> s;
    int zc=0;
    for(auto &nx : s){
      if(nx=='0'){zc++;}
    }
    if(n%2==0){cout << "BOB\n";}
    else if(zc==1){cout << "BOB\n";}
    else if(s[n/2]=='1'){cout << "BOB\n";}
    else{cout << "ALICE\n";}
  }
  return 0;
}