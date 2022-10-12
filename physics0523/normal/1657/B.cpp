#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,b,x,y;
    cin >> n >> b >> x >> y;
    long long res=0,h=0;
    for(long long i=n;i>=1;i--){
      if(h+x>b){
        res-=y*i;
        h-=y;
      }
      else{
        res+=x*i;
        h+=x;
      }
    }
    cout << res << '\n';
  }
  return 0;
}