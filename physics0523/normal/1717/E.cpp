#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int maxn=100005;
  vector<vector<int>> div(maxn);

  for(int i=2;i<maxn;i++){
    for(int j=2*i;j<maxn;j+=i){
      div[j].push_back(i);
    }

    reverse(div[i].begin(),div[i].end());
  }

  int n;
  cin >> n;

  long long res=0;
  for(int c=1;c<=n-2;c++){
    int apb=n-c;
    vector<pair<int,int>> vp;

    for(auto &nx : div[apb]){
      int g=gcd(nx,c);
      int cur=(apb/nx)-1;
      if(cur<=0){continue;}

      for(auto &ny : vp){
        if(ny.first%nx==0){cur-=ny.second;}
      }

      long long del=c;
      del*=nx;del/=g;
      del%=mod;
      // cerr << c << " " << nx << " " << del << " " << cur << "\n";

      del*=cur;del%=mod;

      res+=del;res%=mod;
      if(cur>0){vp.push_back({nx,cur});}
    }

    long long rem=n-c-1;
    for(auto &nx : vp){rem-=nx.second;}
    // coprime
    // cout << c << " " << rem << "\n";
    rem*=c;rem%=mod;
    res+=rem;res%=mod;
  }
  cout << res << "\n";
  return 0;
}