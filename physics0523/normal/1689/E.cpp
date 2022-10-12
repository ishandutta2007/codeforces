#include<bits/stdc++.h>

using namespace std;

struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) { }
  bool unionSet(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x) {
    return -data[root(x)];
  }
};

int n;
int a[2048];
bool jud(){
  int fl=a[0];
  for(int k=0;k<30;k++){
    for(int i=0;i<n;i++){
      if(fl&a[i]){fl|=a[i];}
    }
  }
  bool res=true;
  for(int i=0;i<n;i++){
    if((fl&a[i])==0){res=false;}
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    cin >> n;
    int res=0;
    for(int i=0;i<n;i++){
      cin >> a[i];
      if(a[i]==0){
        a[i]++;
        res++;
      }
    }
    if(jud()){
      cout << res << '\n';
      for(int i=0;i<n;i++){
        if(i){cout << ' ';}
        cout << a[i];
      }cout << '\n';
      continue;
    }

    bool fd=false;
    for(int i=0;i<n;i++){
      if(a[i]>0){
        a[i]--;
        if(jud()){fd=true;res++;break;}
        a[i]++;
      }
      a[i]++;
      if(jud()){fd=true;res++;break;}
      a[i]--;
    }
    if(fd){
      cout << res << '\n';
      for(int i=0;i<n;i++){
        if(i){cout << ' ';}
        cout << a[i];
      }cout << '\n';
      continue;
    }

    vector<bool> exi(32,false);
    UnionFind uf(32);
    for(int i=0;i<n;i++){
      int mem=-1;
      for(int j=0;j<31;j++){
        if(a[i]&(1<<j)){
          exi[j]=true;
          if(mem>=0){uf.unionSet(mem,j);}
          mem=j;
        }
      }
    }

    vector<bool> fl(32,true);
    int tg;
    for(int i=0;i<32;i++){
      if(!exi[i]){continue;}
      if(fl[uf.root(i)]){
        fl[uf.root(i)]=false;
        tg=i;
      }
    }
    int ph=0;
    for(int i=0;i<n && ph<2;i++){
      if(a[i]&(1<<tg)){
        if(ph==0){a[i]--;res++;}
        else{a[i]++;res++;}
        ph++;
      }
    }
    cout << res << '\n';
    for(int i=0;i<n;i++){
      if(i){cout << ' ';}
      cout << a[i];
    }cout << '\n';
  }
  return 0;
}