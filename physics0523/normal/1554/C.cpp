#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,m;
    cin >> n >> m;
    if(n>m){cout << "0\n";continue;}
    long long res=0,keep=0;
    for(int i=30;i>=0;i--){
      long long u=(n&(1ll<<i));
      long long v=(m&(1ll<<i));
      if(u==0){
        if(v!=0){res+=(1ll<<i);}
        else{keep=0;}
      }
      else{
        if(v==0){
          break;
        }
        else{keep+=(1ll<<i);}
      }
      if(i==0){
        res+=keep;
        res++;
        break;
      }
    }
    cout << res << '\n';
  }
  return 0;
}