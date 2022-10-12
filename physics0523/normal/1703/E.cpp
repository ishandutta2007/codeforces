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
    vector<vector<int>> a(n,vector<int>(n));
    for(int i=0;i<n;i++){
      string s;
      cin >> s;
      for(int j=0;j<n;j++){
        a[i][j]=s[j]-'0';
      }
    }

    int res=0;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(a[i][j]==2){continue;}
        int cnt=0,sig=0;
        int ci=i,cj=j;

        for(int k=0;k<4;k++){
          if(a[ci][cj]!=2){
            cnt++;
            sig+=a[ci][cj];
            a[ci][cj]=2;
          }
          int ni=cj;
          int nj=n-1-ci;
          ci=ni;
          cj=nj;
        }
        res+=min(cnt-sig,sig);
      }
    }
    cout << res << '\n';
  }
  return 0;
}