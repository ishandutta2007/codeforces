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
    int k;
    cin >> k;
    vector<int> bk(26,0);
    for(int i=0;i<k;i++){
      string c;
      cin >> c;
      bk[c[0]-'a']=1;
    }
    int sp=0;
    string bin;
    for(int i=0;i<l;i++){
      bin.push_back('0'+bk[s[i]-'a']);
      sp=max(sp,bk[s[i]-'a']);
    }
    if(sp==0){cout << "0\n";continue;}
    while(bin.back()=='0'){bin.pop_back();}
    //cout << bin << '\n';
    int res=0,ch=0,pref=0;
    for(auto &nx : bin){
      if(nx=='1'){
        res=max(res,ch+pref);
        ch=0;pref=1;
      }
      else{ch++;}
    }
    cout << res << '\n';
  }
  return 0;
}