#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    long long res=1;
    bool all=true;
    for(int i=0;i<n;i++){
      string s;
      cin >> s;
      for(auto &nx : s){
        if(nx=='#'){res*=2;res%=mod;}
        else{all=false;}
      }
    }
    if(all){res+=(mod-1);res%=mod;}
    cout << res << '\n';
  }
  return 0;
}