#pragma GCC optimize("Ofast")
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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,m;
    cin >> n >> m;
    vector<long long> a(n);
    for(auto &nx : a){cin >> nx;}
    unordered_set<long long,custom_hash> st;
    for(int i=0;i<m;i++){
      long long x,y;
      cin >> x >> y;
      st.insert((x<<32)+y);
    }
    unordered_map<long long,long long,custom_hash> mp;
    for(int i=0;i<n;i++){mp[a[i]]++;}
    vector<vector<long long>> bk(n+5);
    for(auto &nx : mp){bk[nx.second].push_back(nx.first);}
    vector<long long> look;
    for(int i=n;i>=1;i--){
      if(!bk[i].empty()){
        look.push_back(i);
        sort(bk[i].begin(),bk[i].end());
        reverse(bk[i].begin(),bk[i].end());
      }
    }

    long long res=0;
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    reverse(a.begin(),a.end());
    for(auto &nx : a){
      long long cc=mp[nx];
      for(auto &ny : look){
        for(auto &nz : bk[ny]){
          if(nx==nz){continue;}
          long long f=(cc+ny)*(nx+nz);
          if(f<=res){break;}
          if(st.find((min(nx,nz)<<32)+max(nx,nz))!=st.end()){continue;}
          res=f;
          break;
        }
      }
    }
    cout << res << '\n';
  }
  return 0;
}