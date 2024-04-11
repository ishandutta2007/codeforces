#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,x;
    cin >> n >> x;
    vector<int> a(n),b;
    for(auto &nx : a){cin >> nx;}
    b=a;
    sort(b.begin(),b.end());
    bool fl=true;
    for(int i=(n-x);i<x;i++){
      if(a[i]!=b[i]){fl=false;}
    }
    if(fl){cout << "Yes\n";}else{cout << "No\n";}
  }
  return 0;
}