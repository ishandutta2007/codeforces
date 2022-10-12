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
    for(int i=n-2;i>=0;i-=2){
      if(a[i]>a[i+1]){swap(a[i],a[i+1]);}
    }
    bool isok=true;
    for(int i=1;i<n;i++){
      if(a[i-1]>a[i]){isok=false;}
    }
    if(isok){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}