//#pragma GCC diagnostic error "-std=c++11"
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll n, l=1, r=1.8e9, w;

void prt(ll t){
  cout<<t/2<<' '<<1-t%2<<endl;
}

int main(){
  for (cin>>n;n--;){
    ll mid=l+r>>1;
    prt(mid);
    fflush(stdout);
    string s; cin>>s;
    if (s[0]=='b') l=mid+1, w=mid;
    else r=mid-1;
  }
  if (w%2==0){
    cout<<w/2+1<<' '<<2<<' '<<w/2+3<<' '<<5<<endl;
  }else{
    cout<<w/2+1<<' '<<100<<' '<<w/2+2<<' '<<10000000<<endl;
  }
  fflush(stdout);
}