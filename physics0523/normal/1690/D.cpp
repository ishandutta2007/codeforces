#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    string s;
    cin >> n >> k >> s;
    vector<int> rw(n+1,0);
    for(int i=0;i<n;i++){
      int cv=1;
      if(s[i]=='B'){cv=0;}
      rw[i+1]=rw[i]+cv;
    }
    int res=1e9;
    for(int i=k;i<=n;i++){
      res=min(res,rw[i]-rw[i-k]);
    }
    cout << res << '\n';
  }
  return 0;
}