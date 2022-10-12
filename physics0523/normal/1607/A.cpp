#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    string s,t;
    cin >> s >> t;
    vector<int> d(512,0);
    for(int i=0;i<s.size();i++){
      d[s[i]]=i;
    }
    int res=0;
    for(int i=1;i<t.size();i++){
      res+=abs(d[t[i]]-d[t[i-1]]);
    }
    cout << res << '\n';
  }
  return 0;
}