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
    vector<vector<int>> a(n,vector<int>(5));
    for(auto &nx : a){
      for(auto &ny : nx){cin >> ny;}
    }
    bool fl=false;
    for(int i=0;i<5;i++){
      for(int j=i+1;j<5;j++){
        int ic=0,jc=0;
        for(int k=0;k<n;k++){
          if(a[k][i]==0&&a[k][j]==0){ic=-1e9;jc=-1e9;break;}
          ic+=a[k][i];
          jc+=a[k][j];
        }
        if(min(ic,jc)>=(n/2)){fl=true;}
      }
    }
    if(fl){cout << "YES\n";}else{cout << "NO\n";}
  }
  return 0;
}