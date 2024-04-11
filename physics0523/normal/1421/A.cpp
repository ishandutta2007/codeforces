#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long a,b;
    cin >> a >> b;
    long long res=0;
    for(int i=0;i<40;i++){
      long long cnt=0;
      if(a&(1ll<<i)){cnt++;}
      if(b&(1ll<<i)){cnt++;}
      if(cnt==1){res+=(1ll<<i);}
    }
    cout << res << '\n';
  }
  return 0;
}