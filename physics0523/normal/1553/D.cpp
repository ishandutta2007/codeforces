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
    int sl=s.size();
    int tl=t.size();
    if(sl<tl){cout << "NO\n";continue;}
    if(sl==tl){
      if(s==t){cout << "YES\n";}
      else{cout << "NO\n";}
      continue;
    }
    if((sl-tl)%2==1){s.erase(0,1);}
    //cout << s << ' ' << t << '\n';
    int sp=0,tp=0;
    while(sp<s.size() && tp!=t.size()){
      //cout << sp << ' ' << tp << '\n';
      if(s[sp]==t[tp]){sp++;tp++;}
      else{sp+=2;}
    }
    if(tp==t.size()){cout << "YES\n";}else{cout << "NO\n";}
  }
  return 0;
}