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
    vector<vector<int>> bk(1005);
    for(int i=1;i<=n;i++){
      int v;
      cin >> v;
      bk[v].push_back(i);
    }
    for(int i=1;i<1005;i++){reverse(bk[i].begin(),bk[i].end());}
    int res=-1;
    for(int i=1;i<1005;i++){
      for(int j=1;j<1005;j++){
        if(gcd(i,j)!=1){continue;}
        if(bk[i].empty()){continue;}
        if(bk[j].empty()){continue;}
        res=max(res,bk[i][0]+bk[j][0]);
      }
    }
    cout << res << "\n";
  }
  return 0;
}