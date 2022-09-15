#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  cin>>T;
  for(int i=0;i<T;i++){
    int64_t x,y,k;
    cin>>x>>y>>k;
    cout<<k+((y*k+k)-1+x-2)/(x-1)<<endl;
  }
}