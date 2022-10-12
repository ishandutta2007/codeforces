#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,w;
  cin >> n >> w;
  long long mi=0,ma=0,h=0;
  for(int i=0;i<n;i++){
    long long a;
    cin >> a;
    h+=a;
    mi=min(mi,h);
    ma=max(ma,h);
  }
  cout << max(0ll,w-(ma-mi-1)) << '\n';
  return 0;
}