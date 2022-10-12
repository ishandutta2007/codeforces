#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k;
    cin >> n >> k;
    k%=4;
    if(k==0){cout << "NO\n";continue;}
    cout << "YES\n";
    for(int i=0;i<(n/2);i++){
      int l=2*i+1,r=2*i+2;
      if(((l+k)*r)%4==0){cout << l << " " << r << "\n";}
      else{cout << r << " " << l << "\n";}
    }
  }
  return 0;
}