#include<bits/stdc++.h>

using namespace std;

long long llsankaku(long long x){return ((1+x)*x)/2;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,m;
    cin >> n >> m;
    long long res=llsankaku(m);
    res+=m*llsankaku(n);
    res-=m;
    cout << res << '\n';
  }
  return 0;
}