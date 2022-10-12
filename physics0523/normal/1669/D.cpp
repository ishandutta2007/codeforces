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
    string s;
    cin >> n >> s;
    s.push_back('W');
    bool fl=true;
    int cp=0;
    for(int i=0;i<=n;i++){
      if(s[i]=='W'){
        if(cp==1 || cp==2){fl=false;break;}
        cp=0;
      }
      else if(s[i]=='R'){cp|=1;}
      else{cp|=2;}
    }
    if(fl){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}