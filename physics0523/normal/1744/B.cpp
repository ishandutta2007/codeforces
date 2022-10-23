#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,q;
    cin >> n >> q;
    long long res=0;
    vector<long long> s(2,0);
    for(int i=0;i<n;i++){
      long long v;
      cin >> v;
      s[v%2]++;
      res+=v;
    }
    for(int i=0;i<q;i++){
      long long typ,x;
      cin >> typ >> x;
      if(typ==0){
        res+=s[0]*x;
        if(x%2){
          s[1]+=s[0];
          s[0]=0;
        }
      }
      else{
        res+=s[1]*x;
        if(x%2){
          s[0]+=s[1];
          s[1]=0;
        }
      }
      cout << res << "\n";
    }
  }
  return 0;
}