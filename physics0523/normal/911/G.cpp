#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>

using namespace std;

int bsize=64;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<unsigned long long>> bs(105,vector<unsigned long long>(3200,0));
  for(int i=0;i<n;i++){
    int v;
    cin >> v;
    int p=i/bsize;
    int q=i%bsize;
    bs[v][p]|=(1ull<<q);
  }
  int q;
  cin >> q;
  for(int i=0;i<q;i++){
    int l,r,x,y;
    cin >> l >> r >> x >> y;
    if(x==y){continue;}
    l--;r--;
    while(l<=r){
      if(l%bsize==0 && (l+bsize-1)<=r){
        bs[y][l/bsize]|=bs[x][l/bsize];
        bs[x][l/bsize]=0;
        l+=bsize;
      }
      else{
        if(bs[x][l/bsize]&(1ull<<(l%bsize))){
          bs[y][l/bsize]|=(1ull<<(l%bsize));
          bs[x][l/bsize]^=(1ull<<(l%bsize));
        }
        l++;
      }
    }
  }
  for(int i=0;i<n;i++){
    if(i){cout << ' ';}
    for(int j=1;j<=100;j++){
      if(bs[j][i/bsize]&(1ull<<(i%bsize))){
        cout << j;
        break;
      }
    }
  }cout << '\n';
  return 0;
}