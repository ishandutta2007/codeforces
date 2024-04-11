#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int q;
  cin >> q;
  while(q>0){
    q--;

    int n,m;
    cin >> n >> m;
    string s,t;
    cin >> s >> t;
    bool fl=true;
    for(int i=0;i<m-1;i++){
      if(s[n-i-1]!=t[m-i-1]){fl=false;}
    }
    bool fl2=false;
    for(int i=m-1;i<n;i++){
      if(s[n-i-1]==t[0]){fl2=true;}
    }
    fl&=fl2;
    if(fl){cout << "YES\n";}
    else{cout << "NO\n";}
  }
  return 0;
}