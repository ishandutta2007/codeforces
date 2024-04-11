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
    vector<int> a(n);
    for(auto &nx : a){cin >> nx;}
    string s;
    cin >> s;
    vector<int> b,r;
    for(int i=0;i<n;i++){
      if(s[i]=='B'){b.push_back(a[i]);}
      if(s[i]=='R'){r.push_back(a[i]);}
    }
    sort(b.begin(),b.end());
    sort(r.begin(),r.end());
    int cv=1;
    bool fl=true;
    for(auto &nx : b){
      if(nx<cv){fl=false;}
      cv++;
    }
    for(auto &nx : r){
      if(cv<nx){fl=false;}
      cv++;
    }
    if(fl){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}