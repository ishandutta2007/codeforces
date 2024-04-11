#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;
  int t,g;
  for(int i=0;i<n;i++){
    if(s[i]=='T'){t=i;}
    if(s[i]=='G'){g=i;}
  }
  if(t>g){swap(t,g);}
  if((g-t)%k){cout << "NO\n";return 0;}
  for(int i=t;i<=g;i+=k){
    if(s[i]=='#'){cout << "NO\n";return 0;}
  }
  cout << "YES\n";
  return 0;
}