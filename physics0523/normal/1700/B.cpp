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
    cin >> n;
    string s;
    cin >> s;
    if(s[0]!='9'){
      // 99...9
      for(int i=0;i<n;i++){
        cout << (char)((9-(s[i]-'0'))+'0');
      }cout << '\n';
    }
    else{
      // 111...1
      string res=s;
      int v=0;
      for(int i=n-1;i>=0;i--){
        v+=(s[i]-'0');
        if(v<=1){
          res[i]=((1-v)+'0');
        }
        else{
          res[i]=((11-v)+'0');
        }
        v+=(res[i]-'0');
        v/=10;
      }
      cout << res << '\n';
    }
  }
  return 0;
}