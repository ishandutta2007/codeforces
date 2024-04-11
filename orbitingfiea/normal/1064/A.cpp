//#pragma GCC diagnostic error "-std=c++11"
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
using namespace std;

int a[3];

int main(){
  cin>>a[0]>>a[1]>>a[2];
  sort(a,a+3);
  printf("%d\n",max(0,a[2]-a[0]-a[1]+1));
}