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
    long long n,k,res=0,del=1;
    cin >> n >> k;
    for(int i=0;i<40;i++){
      if(k&(1ll<<i)){res+=del;res%=mod;}
      del*=n;del%=mod;
    }
    cout << res << '\n';
  }
  return 0;
}