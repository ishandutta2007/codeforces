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
    int l=s.size();
    vector<int> bk(32,-1);
    for(int i=0;i<l;i++){
      bk[s[i]-'a']=max(bk[s[i]-'a'],i);
    }
    int tg=1e9;
    for(auto &nx : bk){
      if(nx!=-1){tg=min(tg,nx);}
    }
    for(int i=tg;i<l;i++){cout << s[i];}
    cout << '\n';
  }
  return 0;
}