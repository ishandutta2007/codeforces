#include<bits/stdc++.h>

using namespace std;

bool jud(char a,char b,
         char c,char d){
  int val=0;
  val+=(a-'0');
  val+=(b-'0');
  val+=(c-'0');
  val+=(d-'0');
  if(val==3){return false;}
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    vector<string> s(n);
    for(auto &nx : s){cin >> nx;}
    bool ok=true;
    for(int i=0;i<n-1;i++){
      for(int j=0;j<m-1;j++){
        ok&=jud(s[i][j],s[i][j+1],s[i+1][j],s[i+1][j+1]);
      }
    }
    if(ok){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}