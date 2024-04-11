#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  string s;
  cin >> n >> s;
  int sig=0;
  for(auto &nx : s){
    sig+=(nx-'0');
  }
  if(sig==0){cout << "YES\n";return 0;}
  vector<int> dl;
  if(sig>=2){dl.push_back(1);}
  for(int i=2;i*i<=sig;i++){
    if(sig%i){continue;}
    dl.push_back(i);
    if(sig!=i*i){dl.push_back(sig/i);}
  }
  for(auto &nx : dl){
    bool isok=true;
    int cs=0;
    for(auto &ny : s){
      cs+=(ny-'0');
      if(cs==nx){cs=0;}
      if(cs>nx){isok=false;break;}
    }
    if(isok){cout << "YES\n";return 0;}
  }
  cout << "NO\n";return 0;
  return 0;
}