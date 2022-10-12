#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define mod 1000000007
#define bs 62

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  long long p2[256];
  p2[0]=1;
  for(int i=1;i<256;i++){p2[i]=(p2[i-1]+p2[i-1])%mod;}

  while(t>0){
    t--;
    long long n;
    cin >> n;
    vector<long long> mem(64);
    vector<long long> a(n);
    for(int i=0;i<n;i++){
      cin >> a[i];
      for(int j=0;j<bs;j++){
        if(a[i]&(1ll<<j)){mem[j]++;}
      }
    }

    long long res=0;
    long long ef=mod;ef*=mod;
    long long fb=((1ll<<bs)-1)%mod;

    for(int i=0;i<n;i++){
      vector<int> ank,ork;
      for(int j=0;j<bs;j++){
        if(a[i]&(1ll<<j)){ank.push_back(j);}
        else{ork.push_back(j);}
      }
      for(auto &ae : ank){
        long long ca=mem[ae];
        //printf("<%d : %d>",ae,mem[ae]);
        long long cv=0;
        cv=(((p2[ae]*fb)%mod)*n)%mod;
        cv+=ef;
        for(auto &oe : ork){
          //printf("[%d : %d]",oe,n-mem[oe]);
          cv-=p2[ae+oe]*(n-mem[oe]);
        }
        cv%=mod;
        res+=(ca*cv)%mod;
        res%=mod;
      }//printf("\n");
    }
    cout << res << '\n';
  }
}