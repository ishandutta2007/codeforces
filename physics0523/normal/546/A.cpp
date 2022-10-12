#include<bits/stdc++.h>

using namespace std;

long long llsankaku(long long x){return ((1+x)*x)/2;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long k,n,w;
  cin >> k >> n >> w;
  w=llsankaku(w);
  cout << max(0ll,k*w-n);
  return 0;
}