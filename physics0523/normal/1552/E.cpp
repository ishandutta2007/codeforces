#include<bits/stdc++.h>
#include <chrono>

using namespace std;
using pi=pair<int,int>;

int ceil(int a,int b){if(a%b==0){return a/b;}return (a/b)+1;}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;
  cin >> n >> k;
  vector<int> a(n*k+1);
  for(int i=1;i<=n*k;i++){cin >> a[i];}
  int lim=ceil(n,k-1);
  vector<pi> res(n+1,{-1,-1});
  vector<bool> fl(n+1,true);
  for(int i=0;i<lim;i++){
    int cp=1;
    while(cp<=n*k){
      unordered_map<int,int,custom_hash> mp;
      bool ok=false;
      while(cp<=n*k){
        if(mp[a[cp]]!=0 && fl[a[cp]]){ok=true;break;}
        mp[a[cp]]=cp;cp++;
      }
      if(ok){
        fl[a[cp]]=false;
        res[a[cp]].first=mp[a[cp]];
        res[a[cp]].second=cp;
        cp++;
      }
      else{break;}
    }
  }
  for(int i=1;i<=n;i++){cout << res[i].first << ' ' << res[i].second << '\n';}
  return 0;
}