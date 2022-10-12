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
    int res=1;
    for(int i=0;i<n;i++){
      if(i>=1 && a[i]==0 && a[i-1]==0){res=-1;break;}
      if(a[i]==1){
        if(i>=1 && a[i-1]==1){res+=5;}
        else{res++;}
      }
    }
    cout << res << '\n';
  }
  return 0;
}