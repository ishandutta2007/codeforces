#include<bits/stdc++.h>

using namespace std;

#include <chrono>
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

vector<vector<pair<int,int>>> pfact;
void pf_calc(int mx){
  pfact.resize(mx);
  for(int i=2;i<mx;i++){
    if(!pfact[i].empty()){continue;}
    for(int j=i;j<mx;j+=i){
      int cj=j,cnt=0;
      while(cj%i==0){cj/=i;cnt++;}
      pfact[j].push_back({i,cnt});
    }
  }
}

bool avd_validate(int n,vector<int> avd){
  sort(avd.begin(),avd.end());
  int sz=(n-avd.size())%2;
  avd.push_back(-1);
  int pt=0;
  vector<int> cnt(n+1,0);
  for(int i=1;i<=n;i++){
    bool ers=true;
    if(avd[pt]==i){pt++;ers=false;}
    for(auto &nx : pfact[i]){
      cnt[nx.first]+=(sz*nx.second)%2;
    }
    if(ers){sz++;sz%=2;}
  }
  for(auto &nx : cnt){
    if(nx%2){return false;}
  }
  return true;
}

void avd_print(int n,vector<int> avd){
  sort(avd.begin(),avd.end());
  avd.push_back(-1);
  int pt=0;
  bool fl=false;
  for(int i=1;i<=n;i++){
    if(avd[pt]==i){pt++;continue;}
    if(fl){cout << ' ';}
    cout << i;
    fl=true;
  }cout << '\n';
}

unordered_map<uint64_t,vector<int>, custom_hash> mp;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  std::random_device seed_gen;
  std::mt19937_64 engine(seed_gen());
  int n;
  cin >> n;
  pf_calc(n+1);
  vector<uint64_t> valh(n+1,0),fach(n+1,0);
  uint64_t allh=0;
  for(int i=1;i<=n;i++){
    do{
      valh[i]=engine();
    }while(valh[i]==0);
    uint64_t ch=0;
    for(auto &nx : pfact[i]){
      if(nx.second%2){ch^=valh[nx.first];}
    }
    valh[i]=ch;
    fach[i]=fach[i-1]^valh[i];
    allh^=fach[i];
  }
  if(allh==0){
    vector<int> avd={};
    if(avd_validate(n,avd)){
      cout << n-avd.size() << '\n';
      avd_print(n,avd);
      return 0;
    }
  }
  for(int i=1;i<=n;i++){
    if(allh==fach[i]){
      vector<int> avd={i};
      if(avd_validate(n,avd)){
        cout << n-avd.size() << '\n';
        avd_print(n,avd);
        return 0;
      }
    }
  }
  if(n%2==0){
    vector<int> avd={2,n/2};
    if(avd_validate(n,avd)){
      cout << n-avd.size() << '\n';
      avd_print(n,avd);
      return 0;
    }
  }
  for(int i=1;i<=n;i++){mp[fach[i]].push_back(i);}
  for(int i=1;i<=n;i++){
    if(fach[i]){
      uint64_t tg=allh^fach[i];
      if(!mp[tg].empty()){
        for(auto &nx : mp[tg]){
          vector<int> avd={i,nx};
          if(avd_validate(n,avd)){
            cout << n-avd.size() << '\n';
            avd_print(n,avd);
            return 0;
          }
        }
      }
    }
  }
  vector<int> avd={2,(n-1)/2,n};
  if(avd_validate(n,avd)){
    cout << n-avd.size() << '\n';
    avd_print(n,avd);
    return 0;
  }
  return 0;
}