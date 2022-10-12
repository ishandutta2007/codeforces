#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int l;
    string s,t;
    cin >> l >> s;
    t=s;
    sort(t.begin(),t.end());
    int res=0;
    for(int i=0;i<l;i++){
      if(s[i]!=t[i]){res++;}
    }
    cout << res << '\n';
  }
  return 0;
}