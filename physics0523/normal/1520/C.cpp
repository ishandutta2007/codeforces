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
    if(n==1){cout << "1\n";continue;}
    else if(n==2){cout << "-1\n";continue;}
    vector<vector<int>> res(n,vector<int>(n,0));
    int pt=1;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if((i+j)%2){continue;}
        res[i][j]=pt;pt++;
      }
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(res[i][j]){continue;}
        res[i][j]=pt;pt++;
      }
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(j){cout << ' ';}
        cout << res[i][j];
      }cout << '\n';
    }
  }
  return 0;
}