#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    vector<string> s(n);
    vector<vector<int>> bk(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
      cin >> s[i];
      for(int j=0;j<m;j++){
        if(j){bk[i][j]=bk[i][j-1];}
        if(s[i][j]=='*'){bk[i][j]++;}
      }
    }
    int res=0;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        int l=j,r=j;
        for(int k=0;(i+k<n && 0<=l && r<m);k++){
          int cnt=bk[i+k][r];
          if(l){cnt-=bk[i+k][l-1];}
          if(cnt!=r-l+1){break;}
          res++;
          l--;r++;
        }
      }
    }
    cout << res << '\n';
  }
  return 0;
}