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
    if(l%2){cout << "NO\n";continue;}
    int p=0,q=(l/2);
    bool fl=true;
    for(int i=0;i<(l/2);i++){
      if(s[p]!=s[q]){fl=false;}
      p++;q++;
    }
    if(fl){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}