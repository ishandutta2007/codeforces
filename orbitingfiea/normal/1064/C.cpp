//#pragma GCC diagnostic error "-std=c++11"
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
using namespace std;

int n;
char s[101000];

int main(){
  cin>>n>>s+1;
  sort(s+1,s+n+1);
  cout<<s+1<<endl;
}