#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,v;
    cin >> n >> v;
    long long l=v,r=0;
    for(int i=1;i<n;i++){
      long long v;
      cin >> v;
      if(l*v<0){
        r+=l;
        l=v;
      }
      else{l=max(l,v);}
    }
    r+=l;
    cout << r << '\n';
  }
  return 0;
}