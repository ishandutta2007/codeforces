#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    if(k%2==1){
      for(auto &nx : s){
        nx=('0'+'1'-nx);
      }
    }
    vector<int> mem(n,0);
    for(int i=0;i<n;i++){
      if(s[i]=='0' && k>0){
        k--;
        mem[i]++;
        s[i]='1';
      }
    }
    if(k>0){
      mem[n-1]+=k;
      if(k%2){s[n-1]=('0'+'1'-s[n-1]);}
    }

    cout << s << '\n';
    for(int i=0;i<n;i++){
      if(i){cout << ' ';}
      cout << mem[i];
    }cout << '\n';
  }
  return 0;
}