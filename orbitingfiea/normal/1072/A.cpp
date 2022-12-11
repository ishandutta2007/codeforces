#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
using namespace std;

int n, m, k, ans;

int main(){
  cin>>n>>m>>k;
  for (;k--;){
    ans+=(n-1+m-1)*2;
    n-=4; m-=4;
  }
  cout<<ans<<endl;
}