#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>

using namespace std;
using Graph=vector<vector<int>>;

int search(int x,vector<int> &a){
  int n=a.size();
  int st=0,fi=n-1,te;
  while(st<=fi){
    te=(st+fi)/2;
    if(a[te]<x){st=te+1;}else{fi=te-1;}
  }
  return st;
}

int cnt(int l,int r,vector<int> &a){
  return search(r+1,a)-search(l,a);
}

int get_rand(int lim,mt19937_64 &eg){
  return (int)(eg()%lim);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  std::random_device seed_gen;
  std::mt19937_64 engine(seed_gen());

  int init=0;
  int n,q;
  cin >> n >> q;
  init^=(810893+n);
  init^=(364364+q);

  vector<int> a(n+1);
  Graph g(n+1);
  for(int i=1;i<=n;i++){
    cin >> a[i];
    g[a[i]].push_back(i);
    init^=((114514+i)^a[i]);
  }
  for(int i=0;i<1919+(init%143000);i++){engine();}

  while(q>0){
    q--;
    int l,r;
    cin >> l >> r;

    int tg=a[l];
    int tc=cnt(l,r,g[tg]);

    for(int i=0;i<60;i++){
      int pt=l+get_rand(r-l+1,engine);
      if(a[pt]==tg){continue;}
      int cc=cnt(l,r,g[a[pt]]);
      if(tc<cc){tc=cc;tg=a[pt];}
    }

    int ot=(r-l+1)-tc;
    cout << max(1,tc-ot) << '\n';
  }
  return 0;
}