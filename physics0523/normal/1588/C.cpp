#include<bits/stdc++.h>
#define llinf 4154118101919364364

using namespace std;
using pl=pair<long long,long long>;

void add(set<pl> &st,long long v){
  auto it=st.lower_bound({v,-llinf});
  if(it!=st.end() && (*it).first==v){
    pl op=(*it);
    st.erase(it);
    op.second++;
    st.insert(op);
  }
  else{
    st.insert({v,1});
  }
}

long long delta(set<pl> &st,long long v){
  auto it=st.lower_bound({v,-llinf});
  if(it!=st.end() && (*it).first==v){return (*it).second;}
  return 0;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    long long cf=0,res=0;
    set<pl> sp;
    for(long long i=0;i<n;i++){
      long long v;
      cin >> v;
      if(v==0){res++;}
      if(i%2){
        cf+=v;
        res+=delta(sp,cf);
        add(sp,cf-v);
        while(!sp.empty()){
          auto it=sp.end();it--;
          if((*it).first>cf){sp.erase(it);}
          else{break;}
        }
      }
      else{
        cf-=v;
        res+=delta(sp,cf);
        add(sp,cf+v);
        while(!sp.empty()){
          auto it=sp.begin();
          if((*it).first<cf){sp.erase(it);}
          else{break;}
        }
      }
      //for(auto &nx : sp){cout << i << ':' << nx.first << ' ' << nx.second << '\n';}
    }
    cout << res << '\n';
  }
  return 0;
}