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
    string s;
    cin >> l >> s;
    string res;
    res.push_back(s[0]);
    res.push_back(s[0]);
    for(int i=1;i<l;i++){
      if(s[i-1]<s[i]){break;}
      else if(s[i-1]>s[i]){
        string cand;
        for(int j=0;j<=i;j++){cand.push_back(s[j]);}
        for(int j=i;j>=0;j--){cand.push_back(s[j]);}
        res=min(res,cand);
      }
      else if(i==l-1 || s[i]!=s[i+1]){
        string cand;
        for(int j=0;j<=i;j++){cand.push_back(s[j]);}
        for(int j=i;j>=0;j--){cand.push_back(s[j]);}
        res=min(res,cand);
      }
    }
    cout << res << '\n';
  }
  return 0;
}