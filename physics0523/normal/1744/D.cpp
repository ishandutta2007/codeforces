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
    long long cnt=0;
    for(int i=0;i<n;i++){
      long long x;
      cin >> x;
      while(x%2==0){
        x/=2;
        cnt++;
      }
    }

    long long res=0;
    for(long long i=25;i>=1;i--){
      for(long long j=(1ll<<i);j<=n;j+=(1ll<<(i+1))){
        if(cnt<n){
          cnt+=i;
          res++;
        }
      }
    }
    if(cnt<n){res=-1;}
    cout << res << "\n";
  }
  return 0;
}