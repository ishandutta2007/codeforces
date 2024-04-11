// Segtree and RMQ - repair pos
// CFR353-E
// https://codeforces.com/contest/675/problem/E
#include<bits/stdc++.h>
#define inf 1072114514

using namespace std;
using pi=pair<int,int>;

int ssize=524288;
pi stree[1048576];

#define con max

pi vd=make_pair(-inf,-inf);

void sinit(){
  for(int i=0;i<2*ssize;i++){stree[i]=vd;}
}

void upd(int k,pi a){
  k+=ssize-1;
  stree[k]=a;
  while(k>0){
    k=(k-1)/2;
    stree[k]=con(stree[2*k+1],stree[2*k+2]);
  }
}

// [a,b)
// call:k=0,l=0,r=ssize
pi query(int a,int b,int k,int l,int r){
  if(r<=a || b<=l){return vd;}
  if(a<=l && r<=b){return stree[k];}
  else{return con(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2,r));}
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=1;i<n;i++){
    cin >> a[i];
    upd(i,make_pair(a[i],i));
  }
  upd(n,make_pair(n,n));
  vector<long long> dp(n+1,0);
  long long res=0;
  for(int i=n-1;i>=1;i--){
    pi cv=query(i+1,a[i]+1,0,0,ssize);
    int cp=cv.second;
    dp[i]=dp[cp]+(n-i)-(a[i]-cp);
    res+=dp[i];
  }
  cout << res << '\n';
  return 0;
}