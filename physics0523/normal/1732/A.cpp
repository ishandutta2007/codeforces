#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &nx : a){cin >> nx;}
    int g=a[0];
    for(auto &nx : a){g=gcd(g,nx);}
    if(g==1){
      cout << "0\n";
      continue;
    }

    bool jud=true;
    int res;
    for(int i=n-1;i>=n-2;i--){
      int aft=gcd(a[i],(i+1));
      if(gcd(g,aft)==1){
        cout << n-i << "\n";
        jud=false;
        break;
      }
    }
    if(jud){
      // gcd(a[n-1],n) , gcd(a[n-2],n-1)
      // gcd(n,n-1) == 1
      cout << "3\n";
    }
  }
  return 0;
}