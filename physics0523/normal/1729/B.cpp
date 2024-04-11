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
    string s,res;
    cin >> n >> s;
    int i=n-1;
    while(i>=0){
      int v;
      if(s[i]=='0'){
        v=(s[i-2]-'0')*10+(s[i-1]-'0');
        i-=3;
      }
      else{
        v=(s[i]-'0');
        i--;
      }
      res.push_back('a'+v-1);
    }
    reverse(res.begin(),res.end());
    cout << res << "\n";
  }
  return 0;
}