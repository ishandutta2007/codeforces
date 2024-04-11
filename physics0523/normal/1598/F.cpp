#include<bits/stdc++.h>

using namespace std;

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

long long comp(int x,int y){
  return (((long long)x)<<32)+y;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<string> s(n);
  vector<int> del(n,0);
  vector<int> tz(n,0);
  unordered_map<long long,int,custom_hash> mp;
  for(int i=0;i<n;i++){
    cin >> s[i];
    for(auto &nx : s[i]){
      if(nx=='('){del[i]++;}else{del[i]--;}
      tz[i]=min(tz[i],del[i]);
      if(tz[i]==del[i]){mp[comp(i,tz[i])]++;}
    }
  }
  vector<int> dp((1<<n),-(1<<30));
  dp[0]=0;
  int res=0;
  for(int i=0;i<(1<<n);i++){
    if(dp[i]<0){continue;}
    int fl=0;
    for(int j=0;j<n;j++){
      if(i&(1<<j)){fl+=del[j];}
    }
    //cerr << i << ' ' << dp[i] << '\n';
    for(int j=0;j<n;j++){
      if(i&(1<<j)){continue;}
      int cfl=fl,err=0,cnt=dp[i];
      if(fl+tz[j]<0){err++;}
      cnt+=mp[comp(j,-cfl)];
      // for(auto &nx : s[j]){
      //   if(nx=='('){cfl++;}else{cfl--;}
      //   if(cfl<0){err=1;}
      //   if(err==0 && cfl==0){cnt++;}
      // }
      //cerr << i << ' ' << j << ' ' << cnt << '\n';
      res=max(res,cnt);
      if(err==0){dp[i|(1<<j)]=max(dp[i|(1<<j)],cnt);}
    }
  }
  cout << res << '\n';
  return 0;
}