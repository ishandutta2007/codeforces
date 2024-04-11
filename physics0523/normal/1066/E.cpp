#include<bits/stdc++.h>
#define mod 998244353

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t=1;
  //cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    string a,b;
    cin >> a >> b;
    long long res=0,del=0,ce=1;
    for(int i=0;i<m;i++){
      if((n-i-1)>=0 && a[n-i-1]=='1'){del+=ce;del%=mod;}
      ce*=2;ce%=mod;
      if(b[m-i-1]=='1'){res+=del;res%=mod;}
    }
    cout << res << '\n';
  }
  return 0;
}