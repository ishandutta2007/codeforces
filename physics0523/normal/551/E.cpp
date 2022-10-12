#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define div 2001
#define inf 1000000007

using namespace std;

typedef struct{
  int typ;
  int l;
  int r;
  int x;
}query;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,q;
  cin >> n >> q;
  vector<int> a(n);
  for(auto &nx : a){cin >> nx;}

  vector<query> vq(q);
  for(int i=0;i<q;i++){
    cin >> vq[i].typ;
    if(vq[i].typ==1){
      cin >> vq[i].l >> vq[i].r >> vq[i].x;
      vq[i].l--;
      vq[i].r--;
    }
    else{
      cin >> vq[i].x;
    }
  }
  for(int st=0;st<q;st+=div){
    set<int> bas;
    bas.insert(0);
    bas.insert(n);
    for(int i=st;i<min(q,st+div);i++){
      if(vq[i].typ==1){
        bas.insert(vq[i].l);
        bas.insert(vq[i].r+1);
      }
    }
    int id=0;
    vector<int> vbas;
    unordered_map<int,int> mp;
    for(auto &nx : bas){
      //cerr << nx << ' ';
      vbas.push_back(nx);
      mp[nx]=id;
      id++;
    }//cerr << '\n';
    id=0;
    vector<unordered_map<int,int>> mpmi(bas.size()),mpma(bas.size());
    for(int i=0;i<n;i++){
      if((id+1)<vbas.size() && vbas[id+1]==i){id++;}
      if(mpmi[id].find(a[i])==mpmi[id].end()){
        mpmi[id][a[i]]=i;
        mpma[id][a[i]]=i;
      }
      else{
        mpma[id][a[i]]=i;
      }
    }

    vector<int> del(vbas.size(),0);
    for(int i=st;i<min(q,st+div);i++){
      if(vq[i].typ==1){
        for(int j=mp[vq[i].l];j<mp[vq[i].r+1];j++){
          del[j]+=vq[i].x;
          del[j]=min(del[j],inf);
        }
      }
      else{
        int cmi=inf,cma=-inf;
        for(int j=0;j<vbas.size();j++){
          if(mpmi[j].find(vq[i].x-del[j])!=mpmi[j].end()){
            cmi=min(cmi,mpmi[j][vq[i].x-del[j]]);
            cma=max(cma,mpma[j][vq[i].x-del[j]]);
          }
        }
        if(cmi==inf){cout << "-1\n";}
        else{cout << cma-cmi << '\n';}
      }
    }
    for(int i=0;i<vbas.size()-1;i++){
      for(int j=vbas[i];j<vbas[i+1];j++){
        a[j]+=del[i];
        a[j]=min(inf,a[j]);
      }
    }
  }
  return 0;
}