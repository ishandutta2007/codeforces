#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,res=1e9;
    cin >> n;
    vector<int> a(n);
    int b=0,w=0;
    for(auto &nx : a){
      cin >> nx;
      if(nx%2){b++;}else{w++;}
    }
    sort(a.begin(),a.end());
    if(b%2==0){cout << "YES\n";continue;}
    bool isok=false;
    for(int i=1;i<n;i++){
      if(a[i]-a[i-1]==1){isok=true;break;}
    }
    if(isok){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}