#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  string s,t;
  cin >> s >> t;
  vector<int> pre(m),suf(m);
  int tg=0;
  for(int i=0;(i<n && tg<m);i++){
    if(s[i]==t[tg]){pre[tg]=i;tg++;}
  }
  tg=m-1;
  for(int i=n-1;(i>=0 && tg>=0);i--){
    if(s[i]==t[tg]){suf[tg]=i;tg--;}
  }
  int res=1;
  for(int i=1;i<m;i++){
    res=max(res,suf[i]-pre[i-1]);
  }
  cout << res << '\n';
  return 0;
}