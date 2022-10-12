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
    int l=(n-1)/2;
    int r=n/2;
    while(l>0){
      if(s[l-1]==s[r]){l--;}
      else{break;}
    }
    while(r<n-1){
      if(s[l]==s[r+1]){r++;}
      else{break;}
    }
    cout << r-l+1 << '\n';
  }
  return 0;
}