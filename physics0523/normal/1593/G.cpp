#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    string s;
    cin >> s;
    s="*"+s;
    vector<int> odd(s.size()+1,0),even(s.size()+1,0);
    for(int i=1;i<=s.size();i++){
      if(s[i]=='[' || s[i]==']'){
        if(i%2){odd[i]++;}else{even[i]++;}
      }
      odd[i]+=odd[i-1];
      even[i]+=even[i-1];
    }
    int q;
    cin >> q;
    while(q>0){
      q--;
      int l,r;
      cin >> l >> r;
      l--;
      cout << abs((odd[r]-odd[l])-(even[r]-even[l])) << '\n';
    }
  }
  return 0;
}