#include<bits/stdc++.h>

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
    vector<long long> num(n,0);
    for(int i=0;i<n;i++){
      string s;
      cin >> s;
      for(int j=0;j<m;j++){
        if(s[j]=='1'){
          num[i]|=(1ll<<(m-1-j));
        }
      }
    }
    long long id=((1ll<<m)-n-1)/2;
    long long res=0;
    for(int i=m-1;i>=0;i--){
      long long tg=(res|(1ll<<i));
      long long nm=tg;
      for(auto &nx : num){
        if(nx<tg){nm--;}
      }
      //cout << nm << ' ' << tg << '\n';
      if(nm<=id){res|=(1ll<<i);}
    }

    for(int i=m-1;i>=0;i--){
      if(res&(1ll<<i)){cout << "1";}
      else{cout << "0";}
    }cout << '\n';
  }
  return 0;
}