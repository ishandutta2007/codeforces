#include<bits/stdc++.h>
#define bsize 777

using namespace std;

typedef struct{
  int st;
  int fi;
  int id;
}query;

bool qcomp(const query &a,const query &b){
  int ast=a.st;
  int afi=a.fi;
  int bst=b.st;
  int bfi=b.fi;
  ast/=bsize;bst/=bsize;
  if(ast<bst){return true;}
  if(ast>bst){return false;}
  if((ast&1)==0){
    if(afi<bfi){return true;}
    if(afi>bfi){return false;}
  }
  else{
    if(afi<bfi){return false;}
    if(afi>bfi){return true;}
  }
  return (a.id<b.id);
}

int typ[333333];
int cnt[333333]={0};
long long res=0;
int st,fi;

void mo_add(int id){
  res+=cnt[typ[id]];
  cnt[typ[id]]++;
}

void mo_rem(int id){
  cnt[typ[id]]--;
  res-=cnt[typ[id]];
}

long long mo_query(int tst,int tfi){
  if(!(fi<tst)){
    while(st<tst){mo_rem(st);st++;}
    while(tst<st){st--;mo_add(st);}
  }
  while(fi<tfi){fi++;mo_add(fi);}
  while(tfi<fi){mo_rem(fi);fi--;}

  while(st<tst){mo_rem(st);st++;}
  while(tst<st){st--;mo_add(st);}
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,q;
  string s;
  cin >> n >> q >> s;

  int id=0;
  vector<vector<int>> mem(660000);
  int h=330000;
  mem[h].push_back(0);
  for(int i=1;i<=n;i++){
    if(s[i-1]=='('){h++;}
    else{
      for(auto &nx : mem[h]){typ[nx]=id;}
      id++;
      mem[h].clear();
      h--;
    }
    mem[h].push_back(i);
  }
  for(auto &nx : mem){
    if(!nx.empty()){
      for(auto &ny : nx){typ[ny]=id;}
      id++;
    }
  }

  // for(int i=0;i<=n;i++){
  //   cout << typ[i] << ' ';
  // }cout << '\n';

  vector<query> qv(q);
  for(int i=0;i<q;i++){
    int dum;
    cin >> dum >> qv[i].st >> qv[i].fi;
    qv[i].st--;
    qv[i].id=i;
  }
  sort(qv.begin(),qv.end(),qcomp);

  vector<long long> res(q);
  mo_add(0);st=0;fi=0;
  for(int i=0;i<q;i++){res[qv[i].id]=mo_query(qv[i].st,qv[i].fi);}
  for(auto &nx : res){cout << nx << '\n';}
  return 0;
}