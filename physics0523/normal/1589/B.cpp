#include<bits/stdc++.h>

using namespace std;

int main(){
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,m;
    cin >> n >> m;
    cout <<(n*m+2)/3 << '\n';
  }
  return 0;
}