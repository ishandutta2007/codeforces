#include<bits/stdc++.h>

using namespace std;

set<int> dvd(int x){
  set<int> res;
  for(int i=1;i*i<=x;i++){
    if(x%i==0){
      res.insert(i);
      res.insert(x/i);
    }
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> bk(32,0);
    for(auto &nx : a){
      cin >> nx;
      for(int i=0;i<30;i++){
        if(nx&(1<<i)){bk[i]++;}
      }
    }
    set<int> res;
    for(int i=1;i<=n;i++){res.insert(i);}
    for(int i=0;i<30;i++){
      if(bk[i]==0){continue;}
      set<int> nres,cs=dvd(bk[i]);
      for(auto &nx : cs){
        if(res.find(nx) != res.end()){nres.insert(nx);}
      }
      res.swap(nres);
    }
    bool fl=false;
    for(auto &nx : res){
      if(fl){cout << ' ';}
      fl=true;
      cout << nx;
    }cout << '\n';
  }
  return 0;
}