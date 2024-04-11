#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n;
    string s;
    cin >> n >> s;
    long long res=(n*(n+1))/2;
    for(int i=1;i<n;i++){
      if(s[i-1]==s[i]){
        res-=i;
      }
    }
    cout << res << '\n';
  }
  return 0;
}