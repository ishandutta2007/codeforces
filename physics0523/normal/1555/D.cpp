#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<string> pat={"abc","acb","bac","bca","cab","cba"};
  vector<vector<int>> kind(n+1,vector<int>(6,0));
  for(int i=0;i<n;i++){
    for(int j=0;j<6;j++){
      kind[i+1][j]=kind[i][j];
      if(pat[j][i%3]!=s[i]){
        kind[i+1][j]++;
      }
    }
  }
  while(q>0){
    q--;
    int l,r;
    cin >> l >> r;
    l--;
    int res=2*n;
    for(int i=0;i<6;i++){res=min(kind[r][i]-kind[l][i],res);}
    cout << res << '\n';
  }
  return 0;
}