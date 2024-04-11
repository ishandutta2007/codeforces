#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    string s,res;
    cin >> s;
    vector<int> kp(10,0);
    while(!s.empty()){
      // cerr << s << "\n";
      int l=s.size(),tg=0;
      for(int i=0;i<l;i++){
        if(s[tg]>=s[i]){tg=i;}
      }
      for(int i=0;i<(s[tg]-'0');i++){
        while(kp[i]>0){
          res.push_back('0'+i);
          kp[i]--;
        }
      }
      for(int i=0;i<=tg;i++){
        if(s[i]==s[tg]){res.push_back(s[i]);}
        else{kp[min(9,(int)(s[i]-'0')+1)]++;}
      }
      while(kp[s[tg]-'0']>0){
        kp[s[tg]-'0']--;
        res.push_back(s[tg]);
      }
      string rem;
      for(int i=tg+1;i<l;i++){rem.push_back(s[i]);}
      s=rem;
    }
    for(int i=0;i<10;i++){
      while(kp[i]>0){res.push_back('0'+i);kp[i]--;}
    }
    cout << res << "\n";
  }
  return 0;
}