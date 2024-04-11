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

typedef struct{
  int a;
  int b;
  int id;
}dat;

using pi=pair<int,int>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    unordered_map<int, vector<dat>, custom_hash> mp;
    vector<int> a(n),b(n),m(n);
    for(int i=0;i<n;i++){
      cin >> a[i] >> b[i] >> m[i];
      mp[a[i]+b[i]-m[i]].push_back({a[i],b[i],i});
    }
    int rcnt=0;
    vector<pair<int,int>> res(n);
    for(auto &ca : mp){
      int rem=ca.first;
      vector<pair<pi,int>> sg;
      for(auto &nx : ca.second){
        int sub=nx.a+nx.b-rem;
        int l=max(0,nx.a-sub),r=min(rem,nx.a);
        sg.push_back({{l,r},nx.id});
      }
      sort(sg.begin(),sg.end());
      sg.push_back({{2e9,2e9},-1});
      int mir=1e8;
      vector<pair<pi,int>> sl;
      for(auto &nx : sg){
        if(mir<nx.first.first){
          rcnt++;
          for(auto &ny : sl){
            int ci=ny.second;
            res[ci].first=mir;
            res[ci].second=rem-mir;
            res[ci].first=a[ci]-res[ci].first;
            res[ci].second=b[ci]-res[ci].second;
          }
          sl.clear();
          mir=1e8;
        }
        sl.push_back(nx);
        mir=min(mir,nx.first.second);
      }
    }
    cout << rcnt << '\n';
    for(int i=0;i<n;i++){
      cout << res[i].first << ' ';
      cout << res[i].second << '\n';
    }
  }
  return 0;
}