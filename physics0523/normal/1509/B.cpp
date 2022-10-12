#include<bits/stdc++.h>

using namespace std;

bool jud(string &s){
  int fl=0;
  for(auto &nx : s){
    if(nx=='T'){fl++;}else{fl--;}
    if(fl<0){return false;}
  }
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while(tc>0){
    tc--;
    int n;
    string s;
    cin >> n >> s;
    int t=0,m=0;
    for(auto &nx : s){
      if(nx=='T'){t++;}
      else{m++;}
    }
    if(m*2!=t){cout << "NO\n";continue;}
    if(!jud(s)){cout << "NO\n";continue;}
    reverse(s.begin(),s.end());
    if(!jud(s)){cout << "NO\n";continue;}
    cout << "YES\n";
  }
  return 0;
}