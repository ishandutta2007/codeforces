#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>

using namespace std;

int bit[525252]={0},bsize=524288;

long long sum(int i){
  long long s=0;
  while(i>0){
    s+=bit[i];
    i-=i&(-i);
  }
  return s;
}
void add(int i,int x){
  while(i<bsize){
    bit[i]+=x;
    i+=i&(-i);
  }
}

int n;

long long ivs(vector<int> &arr){
  long long res=0;
  vector<pair<int,int>> cv;
  for(int i=0;i<bsize;i++){bit[i]=0;}
  for(int i=0;i<n;i++){cv.emplace_back(make_pair(arr[i],i));}
  sort(cv.begin(),cv.end());
  for(int i=0;i<n;i++){arr[cv[i].second]=(i+1);}
  for(int i=0;i<n;i++){
    res+=(i-sum(arr[i]));
    add(arr[i],1);
  }
  return res;
}

signed main(){
  int mask = random_device()();
  int rx=0;
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  vector<int> cz(16777216,0),co(16777216,0);
  vector<int> ac(n);
  for(int i=30;i>=6;i--){
    long long ivz=0,ivo=0;
    for(int j=0;j<n;j++){
      int ky=(a[j]>>(i+1));
      if(a[j]&(1<<i)){
        co[ky]++;
        ivo+=cz[ky];
      }
      else{cz[ky]++;ivz+=co[ky];}
      ac[j]=ky;
    }
    if(ivz>ivo){rx+=(1<<i);}
    for(int j=0;j<n;j++){cz[ac[j]]=0;co[ac[j]]=0;}
  }
  for(int i=5;i>=0;i--){
    unordered_map<int,int> mcz,mco;
    long long ivz=0,ivo=0;
    for(int j=0;j<n;j++){
      int ky=((a[j]>>(i+1))^mask);
      if(a[j]&(1<<i)){
        mco[ky]++;
        ivo+=mcz[ky];
      }
      else{mcz[ky]++;ivz+=mco[ky];}
    }
    if(ivz>ivo){rx+=(1<<i);}
  }
  for(int j=0;j<n;j++){a[j]^=rx;}
  cout << ivs(a) << ' ' << rx << '\n';
  return 0;
}