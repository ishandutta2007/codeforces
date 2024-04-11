#include<bits/stdc++.h>

using namespace std;

long long llsankaku(long long x){return ((1+x)*x)/2;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<long long> f={1,2};
  for(long long i=2;;i++){
    f.push_back(f[i-1]+f[i-2]);
    if(f[i]>2e18){break;}
  }
  int t=1;
  while(t>0){
    t--;
    long long n;
    cin >> n;
    for(int i=1;;i++){
      if(n<f[i]){cout << i-1 << "\n";break;}
    }
  }
  return 0;
}