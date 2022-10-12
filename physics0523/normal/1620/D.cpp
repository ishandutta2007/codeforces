#include<bits/stdc++.h>

using namespace std;

int ceil(int a,int b){if(a%b==0){return a/b;}return (a/b)+1;}

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
    for(auto &nx : a){cin >> nx;}
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    int res=ceil(a[0],3)+1;
    bool dec=false;
    if(a[0]%3==0){
      // 3,3,3,...
      bool ok=true;
      for(auto &nx : a){
        if(nx%3!=0){ok=false;}
      }
      if(ok){dec=true;}
    }
    if(a[0]%3==1){
      // 1,3,3,...
      bool ok=true;
      for(auto &nx : a){
        if(nx%3==2){ok=false;}
      }
      if(ok){dec=true;}

      // 2,2,3,...
      ok=true;
      for(auto &nx : a){
        if(nx==1 || nx==(a[0]-1)){ok=false;}
      }
      if(ok){dec=true;}
    }
    if(a[0]%3==2){
      // 2,3,3,...
      bool ok=true;
      for(auto &nx : a){
        if(nx%3==1){ok=false;}
      }
      if(ok){dec=true;}
    }
    if(dec){res--;}
    cout << res << '\n';
  }
  return 0;
}