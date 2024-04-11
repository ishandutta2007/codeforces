#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>

using namespace std;

#define psize 400

typedef struct{
  long long st;
  long long fi;
  long long id;
}query;

bool sortfnc(const query &a,const query &b){
  long long ast=(a.st);
  long long afi=(a.fi);
  long long bst=(b.st);
  long long bfi=(b.fi);
  ast/=psize;bst/=psize;
  if(ast<bst){return true;}
  if(ast>bst){return false;}
  if((ast&1ll)==0){return (afi<bfi);}
  return (afi>bfi);
}

long long search(long long x,vector<long long> &a,long long n){
  long long st=0,fi=n-1,te;
  while(st<=fi){
    te=(st+fi)/2;
    if(a[te]<x){st=te+1;}else{fi=te-1;}
  }
  return st;
}

long long n,k;
long long a[131072];
vector<vector<long long>> mem(1048576);
long long st=0,fi=0;
long long res=0;

void mo_add(long long id){
  long long tg=(a[id]^k);
  long long sst=st,sfi=fi;
  if(st==id){sst++;}
  else if(fi==id){sfi--;}
  long long dlt=search(sfi+1,mem[tg],mem[tg].size()) - search(sst,mem[tg],mem[tg].size());
  res+=dlt;
}

void mo_rem(long long id){
  long long tg=(a[id]^k);
  long long sst=st,sfi=fi;
  if(st==id){sst++;}
  else if(fi==id){sfi--;}
  long long dlt=search(sfi+1,mem[tg],mem[tg].size()) - search(sst,mem[tg],mem[tg].size());
  res-=dlt;
}

long long mo_query(long long tst,long long tfi){
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
  long long q;
  cin >> n >> q >> k;
  mem[0].push_back(0);
  for(long long i=1;i<=n;i++){
    cin >> a[i];
    a[i]^=a[i-1];
    mem[a[i]].push_back(i);
  }

  vector<query> qv(q);
  for(long long i=0;i<q;i++){
    cin >> qv[i].st >> qv[i].fi;
    qv[i].id=i;
    qv[i].st--;
  }
  sort(qv.begin(),qv.end(),sortfnc);

  //cerr << "ok\n";

  mo_add(0);
  res=0;st=0;fi=0;
  vector<long long> res(q);
  for(auto &nx : qv){res[nx.id]=mo_query(nx.st,nx.fi);}
  for(int i=0;i<q;i++){cout << res[i] << '\n';}
  return 0;
}