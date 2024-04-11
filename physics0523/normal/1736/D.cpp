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
    string s;
    cin >> s;
    n*=2;

    int c0=0,c1=0;
    for(auto &nx : s){
      if(nx=='0'){c0++;}
      else{c1++;}
    }
    if(c0%2==1 || c1%2==1){cout << "-1\n";continue;}

    vector<int> pos;
    vector<int> part;
    int tg=0;
    for(int i=0;i<n;i+=2){
      part.push_back(i+1);
      if(s[i]==s[i+1]){continue;}
      if(s[i]==('0'+tg)){pos.push_back(i+1);}
      else{pos.push_back(i+2);}
      tg=1-tg;
    }

    cout << pos.size();
    for(auto &nx : pos){cout << " " << nx;}cout << "\n";
    for(int i=0;i<n/2;i++){
      if(i){cout << " ";}
      cout << part[i];
    }cout << "\n";
  }
  return 0;
}