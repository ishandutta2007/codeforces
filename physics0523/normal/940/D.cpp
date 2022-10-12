#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for(auto &nx : a){cin >> nx;}
  string s;
  cin >> s;
  int l=-1000000000;
  int r=1000000000;
  for(int i=4;i<n;i++){
    if(s[i-4]==s[i-3] && s[i-3]==s[i-2] && s[i-2]==s[i-1] && s[i-1]!=s[i]){
      vector<int> cd={a[i-4],a[i-3],a[i-2],a[i-1],a[i]};
      sort(cd.begin(),cd.end());
      if(s[i]=='1'){l=max(l,cd[4]+1);}
      if(s[i]=='0'){r=min(r,cd[0]-1);}
    }
  }
  cout << l << ' ' << r << '\n';
  return 0;
}