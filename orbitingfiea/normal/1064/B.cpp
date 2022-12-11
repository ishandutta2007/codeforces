//#pragma GCC diagnostic error "-std=c++11"
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
using namespace std;

int T, n, ans;

int main(){
  for (cin>>T;T--;){
    cin>>n; ans=1;
    for (;n;n-=n&-n) ans<<=1;
    cout<<ans<<endl;
  }
}