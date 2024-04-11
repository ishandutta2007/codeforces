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
    int mi=-1,ma=-1;
    for(int i=0;i<s.size();i++){
      if(s[i]=='0'){mi=i;break;}
    }
    for(int i=s.size()-1;i>=0;i--){
      if(s[i]=='0'){ma=i;break;}
    }
    if(mi==-1){cout << "0\n";continue;}
    bool fl=false;
    for(int i=mi;i<=ma;i++){
      if(s[i]=='1'){fl=true;break;}
    }
    if(fl){cout << "2\n";}
    else{cout << "1\n";}
  }
  return 0;
}