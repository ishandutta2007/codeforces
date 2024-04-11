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
    vector<int> a(n),b(n);
    int fl=0;
    for(auto &nx : a){cin >> nx;}
    for(auto &nx : b){
      cin >> nx;
      fl|=(1<<nx);
    }
    if(fl==3){cout << "Yes\n";continue;}
    bool isok=true;
    for(int i=1;i<n;i++){
      if(a[i-1]>a[i]){isok=false;}
    }
    if(isok){cout << "Yes\n";}
    else{cout << "No\n";}
  }
  return 0;
}