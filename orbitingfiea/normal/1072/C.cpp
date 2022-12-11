#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll a, b, n;
vector<int>A, B;

int main(){
  cin>>a>>b;
  for (;(n+1)*(n+2)/2<=a+b;) ++n;
  for (int i=n;i>=1;--i){
    if (a>=i) a-=i, A.push_back(i);
    else B.push_back(i);
  }
  cout<<A.size()<<endl;
  for (auto o:A) printf("%d ",o); puts("");
  cout<<B.size()<<endl;
  for (auto o:B) printf("%d ",o); puts("");
}