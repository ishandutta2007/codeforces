#include<bits/stdc++.h>

using namespace std;

int n;

map<pair<int,int>,int> mp;
int query(int a,int b){
  if(mp[{a,b}]!=0){return mp[{a,b}];}
  cout << "? " << a+1 << ' ' << b+1 << '\n';
  fflush(stdout);
  int res;
  cin >> res;
  mp[{a,b}]=res;
  mp[{b,a}]=res;
  return res;
}

void ans(vector<int> &p){
  cout << "!";
  for(auto &nx : p){cout << ' ' << nx;}
  cout << '\n';
}

int main(){
  std::random_device seed_gen;
  std::mt19937_64 engine(seed_gen());
  cin >> n;
  vector<int> cand;
  for(int i=0;i<n;i++){cand.push_back(i);}
  while(cand.size()>1){
    shuffle(cand.begin(),cand.end(),engine);
    if(cand.size()==2){
      set<int> st;
      st.insert(cand[0]);
      st.insert(cand[1]);
      vector<int> p;
      for(int i=0;i<n;i++){p.push_back(i);}
      shuffle(p.begin(),p.end(),engine);
      for(auto &nx : p){
        if(st.find(nx)==st.end()){
          cand.push_back(nx);break;
        }
      }
    }
    shuffle(cand.begin(),cand.end(),engine);
    int ln=min(8,(int)cand.size());
    vector<int> mem(ln,2047);
    for(int i=0;i<ln;i++){
      for(int j=i+1;j<ln;j++){
        int m=query(cand[i],cand[j]);
        mem[i]&=m;
        mem[j]&=m;
      }
    }
    int tg=0;
    for(int i=1;i<ln;i++){
      if(popcount((uint32_t)mem[i])<popcount((uint32_t)mem[tg])){tg=i;}
    }

    vector<int> ncand={cand[tg]};
    for(auto &nx : cand){
      if(cand[tg]==nx){continue;}
      if((query(cand[tg],nx)|mem[tg])==mem[tg]){ncand.push_back(nx);}
    }
    cand.swap(ncand);
  }
  int zero=cand[0];
  vector<int> p(n);
  p[zero]=0;
  for(int i=0;i<n;i++){
    if(zero!=i){p[i]=query(zero,i);}
  }
  ans(p);
  return 0;
}