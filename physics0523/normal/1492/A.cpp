#include<bits/stdc++.h>

using namespace std;

long long llceil(long long a,long long b){if(a%b==0){return a/b;}return (a/b)+1;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long p,a,b,c;
    cin >> p >> a >> b >> c;
    long long res=8e18;
    res=min(llceil(p,a)*a,res);
    res=min(llceil(p,b)*b,res);
    res=min(llceil(p,c)*c,res);
    cout << res-p << '\n';
  }
  return 0;
}