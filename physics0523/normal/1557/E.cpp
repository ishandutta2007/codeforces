#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

long long get_rand(long long lim,mt19937_64 &eg){
  return (long long)(eg()%lim);
}

map<string,pi> del;

void init(){
  del["Right"]={0,1};
  del["Down-Right"]={1,1};
  del["Down"]={1,0};
  del["Down-Left"]={1,-1};
  del["Left"]={0,-1};
  del["Up-Left"]={-1,-1};
  del["Up"]={-1,0};
  del["Up-Right"]={-1,1};
}

bool validate(pi x){
  if(!(1<=x.first && x.first<=8)){return false;}
  if(!(1<=x.second && x.second<=8)){return false;}
  return true;
}

int remq;
string query(int x,int y){
  remq--;
  cout << x << ' ' << y << '\n';
  fflush(stdout);
  string res;
  cin >> res;
  return res;
}

void kmov(string s,set<pi> &st){
  set<pi> nst;
  int dx=del[s].first;
  int dy=del[s].second;
  for(auto &nx : st){
    pi pd={nx.first+dx,nx.second+dy};
    if(validate(pd)){nst.insert(pd);}
  }
  st.swap(nst);
}

void qtreat(int x,int y,set<pi> &st){
  int p=x+y,m=y-x;
  for(int i=1;i<=8;i++){
    if(st.find({x,i})!=st.end()){st.erase({x,i});}
    if(st.find({i,y})!=st.end()){st.erase({i,y});}
    if(st.find({i,p-i})!=st.end()){st.erase({i,p-i});}
    if(st.find({i,i+m})!=st.end()){st.erase({i,i+m});}
  }
}

const int killq=8;

bool kill(int kx,int ky,int &qx,int &qy,set<pi> &st){
  if(kx==qx){return false;}
  qx=kx;
  string rs=query(qx,qy);
  if(rs=="Done"){return true;}
  kmov(rs,st);
  qtreat(qx,qy,st);
  if(del[rs].first==0){return false;}
  kx+=del[rs].first;
  ky+=del[rs].second;
  if(!validate({kx,ky})){return false;}

  if(ky==qy){return false;}
  qy=ky;
  int exdx=kx-qx;
  for(int i=0;i<7;i++){
    string rs=query(qx,qy);
    if(rs=="Done"){return true;}
    kmov(rs,st);
    qtreat(qx,qy,st);
    if(del[rs].first!=exdx){return false;}
    kx+=del[rs].first;
    ky+=del[rs].second;
    if(!validate({kx,ky})){return false;}
    qx+=del[rs].first;
    qy+=del[rs].second;
    if((!validate({qx,qy})) || i==6){
      qx-=del[rs].first;
      qy-=del[rs].second;
      return false;
    }
  }
  return false;
}

int change(int x,mt19937_64 &engine){
  int v=1+get_rand(7,engine);
  if(v>=x){v++;}
  return v;
}

int main(){
  init();
  std::random_device seed_gen;
  std::mt19937_64 engine(seed_gen());
  int t;
  cin >> t;
  while(t>0){
    t--;
    remq=130;
    set<pi> st;
    for(int i=1;i<=8;i++){
      for(int j=1;j<=8;j++){
        st.insert({i,j});
      }
    }
    int qx,qy;
    int knd=get_rand(4,engine);
    if(knd&1){qx=4;}else{qx=5;}
    if(knd&2){qy=4;}else{qy=5;}
    bool fl=true;
    while(1){
      string rs=query(qx,qy);
      if(rs=="Done"){fl=false;break;}
      kmov(rs,st);
      qtreat(qx,qy,st);
      if(remq>=killq*st.size()){break;}
      if(remq==0){cout << "Lose...\n";return 0;}

      if(get_rand(2,engine)){qx=change(qx,engine);}
      else{qy=change(qy,engine);}
    }
    if(fl){
      while(!st.empty()){
        auto it=st.begin();
        pi cp=(*it);
        if(kill(cp.first,cp.second,qx,qy,st)){break;}
      }
    }
  }
  return 0;
}