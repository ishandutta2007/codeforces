#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  string s,t;
  cin >> n >> s >> t;
  vector<int> a(10),b(10);
  for(int i=0;i<n;i++){
    a[s[i]-'0']++;
    b[t[i]-'0']++;
  }
  
  int res=0,rem=0;
  for(int i=9;i>=0;i--){
    rem+=b[i];
    int fli=max(a[i]-rem,0);
    rem-=(a[i]-fli);
    res+=fli;
  }
  cout << res << '\n';
  
  res=0;rem=0;
  for(int i=9;i>=0;i--){
    int fli=min(rem,a[i]);
    res+=fli;
    rem-=fli;
    rem+=b[i];
  }
  cout << res << '\n';
  return 0;
}