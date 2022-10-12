#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long h,w,n,res=1;
    cin >> h >> w >> n;
    while(h%2==0){h/=2;res*=2;}
    while(w%2==0){w/=2;res*=2;}
    if(res>=n){cout << "YES\n";}else{cout << "NO\n";}
  }
  return 0;
}