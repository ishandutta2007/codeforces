#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> d(n+1,vector<int>(n+1,1e9));
  for(int i=1;i<=n;i++){
    d[i][i]=0;
    string s;
    cin >> s;
    for(int j=0;j<n;j++){
      if(s[j]=='1'){d[i][j+1]=1;}
    }
  }
  for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
      }
    }
  }

  int m;
  cin >> m;
  vector<int> a(m);
  for(int i=0;i<m;i++){cin >> a[i];}

  int dist=1;
  vector<int> res={a[0]};
  for(int i=1;i<m;i++){
    if(d[res.back()][a[i]]!=dist){
      res.push_back(a[i-1]);
      dist=2;
    }
    else{dist++;}
  }
  res.push_back(a[m-1]);

  cout << res.size() << "\n";
  for(int i=0;i<res.size();i++){
    if(i){cout << " ";}
    cout << res[i];
  }cout << "\n";
  return 0;
}