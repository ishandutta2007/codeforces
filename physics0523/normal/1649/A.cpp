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
    int l=n,r=-1;
    for(int i=0;i<n;i++){
      if(a[i]==0){l=i-1;break;}
    }
    for(int i=n-1;i>=0;i--){
      if(a[i]==0){r=i+1;break;}
    }
    cout << max(0,r-l) << '\n';
  }
  return 0;
}