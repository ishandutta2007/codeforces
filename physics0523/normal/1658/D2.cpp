#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define mod 998244353

using namespace std;

bool check(int x,int l,int r,vector<int> &a){
  unordered_set<int> st;
  for(auto &nx : a){
    int v=(nx^x);
    if(!(l<=v && v<=r)){return false;}
    st.insert(v);
  }
  return ((int)st.size()==(r-l+1));
}

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int l,r;
    cin >> l >> r;
    vector<int> a(r-l+1),na;
    int x=0;
    for(auto &nx : a){
      cin >> nx;
    }
    na=a;
    int tg=1;
    bool ex=false;
    while(na.size()>1 && !ex){
      vector<int> sma;
      unordered_set<int> st;
      for(auto &nx : na){
        if(st.find(nx^tg)!=st.end()){
          st.erase(nx^tg);
          sma.push_back(min(nx,(nx^tg)));
        }
        else{st.insert(nx);}
      }
      if(!st.empty()){
        for(auto &nx : st){
          if(check((nx^l),l,r,a)){
            cout << (nx^l) << '\n';
            ex=true;break;
          }
          if(check(((nx+tg-1)^r),l,r,a)){
            cout << ((nx+tg-1)^r) << '\n';
            ex=true;break;
          }
        }
      }
      na=sma;tg*=2;
    }
    if(!ex){
      cout << (na[0]^l) << '\n';
    }
  }
}