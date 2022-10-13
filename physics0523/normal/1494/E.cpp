#include<bits/stdc++.h>

using namespace std;

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

int main(){
  int n,q;
  cin >> n >> q;
  unordered_map<pair<int,int>,int,HashPair> mp;

  int mig=0,odd=0;

  while(q>0){
    q--;
    string typ;
    cin >> typ;
    if(typ[0]=='+'){
      int u,v;
      string c;
      cin >> u >> v >> c;
      mp[make_pair(u,v)]=((int)(c[0]+1-'a'));

      int uv=mp[make_pair(u,v)];
      int vu=mp[make_pair(v,u)];
      if(uv==vu){mig++;}
      else if(uv!=0 && vu!=0){odd++;}
    }
    else if(typ[0]=='-'){
      int u,v;
      cin >> u >> v;
      int uv=mp[make_pair(u,v)];
      int vu=mp[make_pair(v,u)];
      if(uv==vu){mig--;}
      else if(uv!=0 && vu!=0){odd--;}
      mp[make_pair(u,v)]=0;
    }
    else{
      int k;
      cin >> k;
      if(mig>0){cout << "YES\n";}
      else if(odd>0 && k%2==1){cout << "YES\n";}
      else{cout << "NO\n";}
    }
  }
  return 0;
}