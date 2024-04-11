#include<bits/stdc++.h>
#define mod 998244353

using namespace std;

int main(){
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,res=1;
    cin >> n;
    if(n%2){cout << "0\n";continue;}
    n/=2;
    while(n>0){res*=n;res%=mod;n--;}
    res*=res;res%=mod;
    cout << res << '\n';
  }
}