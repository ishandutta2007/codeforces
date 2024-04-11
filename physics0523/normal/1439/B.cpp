#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;
typedef pair<int,int> pi;

struct HashPair {

    static size_t m_hash_pair_random;

    template<class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const {

        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);

        size_t seed = 0;
        seed ^= hash1 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        seed ^= hash2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        seed ^= m_hash_pair_random + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        return seed;
    }
};

size_t HashPair::m_hash_pair_random = (size_t) random_device()();

void vecout(vector<int> v){
  int fl=0;
  for(auto &nx : v){
    if(fl){cout << ' ';}
    fl=1;
    cout << nx;
  }
  cout << '\n';
}

int main(){
  std::random_device seed_gen;
  std::mt19937 engine(seed_gen());

  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    engine();
    t--;
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> fl(n+1,0);
    vector<int> cnt(n+1,0);
    Graph g(n+1);
    unordered_map<pi,int,HashPair> mp;
    for(int i=0;i<m;i++){
      int u,v;
      cin >> u >> v;
      mp[make_pair(u,v)]=1;
      mp[make_pair(v,u)]=1;
      g[u].emplace_back(v);
      g[v].emplace_back(u);
      cnt[u]++;cnt[v]++;
    }
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    for(int i=1;i<=n;i++){
      pq.push(make_pair(cnt[i],i));
    }
    int fa=0;
    int cv=n;
    while(!pq.empty()){
      pi od=pq.top();
      pq.pop();
      if(fl[od.second]==1){continue;}
      if(cnt[od.second]!=od.first){continue;}
      if(od.first==k){
        fa=1;
        vector<int> res;
        for(int i=1;i<=n;i++){
          if(fl[i]==0){res.emplace_back(i);}
        }
        cout << "1 " << res.size() << '\n';
        vecout(res);
        break;
      }
      else if(cv<=323 && od.first==(k-1)){
        vector<int> css;
        css.emplace_back(od.second);
        for(auto &nx : g[od.second]){
          if(fl[nx]==1){continue;}
          css.emplace_back(nx);
        }
        shuffle(css.begin(),css.end(),engine);
        int acf=1;
        for(int i=0;i<k;i++){
          for(int j=i+1;j<k;j++){
            if(mp[make_pair(css[i],css[j])]==0){acf=0;break;}
          }
          if(acf==0){break;}
        }
        if(acf==1){
          fa=1;
          cout << "2\n";
          vecout(css);
          break;
        }
      }
      cv--;fl[od.second]=1;
      for(auto &nx : g[od.second]){
        if(fl[nx]==1){continue;}
        cnt[nx]--;
        pq.push(make_pair(cnt[nx],nx));
      }
    }
    if(fa==0){
      cout << "-1\n";
    }
  }
  return 0;
}