#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>

using namespace std;

//Binary Indexed Tree
long long bit[132000]={0},bsize=131072;
long long sum(long long i){
  long long s=0;
  while(i>0){
    s+=bit[i];
    i-=i&(-i);
  }
  return s;
}
void add(long long i,long long x){
  while(i<=bsize){
    bit[i]+=x;
    i+=i&(-i);
  }
}

int a[131072];
int jud[131072]={0};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  jud[4]=1;jud[7]=1;

  jud[44]=1;jud[47]=1;jud[74]=1;jud[77]=1;

  jud[444]=1;jud[447]=1;jud[474]=1;jud[477]=1;
  jud[744]=1;jud[747]=1;jud[774]=1;jud[777]=1;

  jud[4444]=1;jud[4447]=1;jud[4474]=1;jud[4477]=1;
  jud[4744]=1;jud[4747]=1;jud[4774]=1;jud[4777]=1;
  jud[7444]=1;jud[7447]=1;jud[7474]=1;jud[7477]=1;
  jud[7744]=1;jud[7747]=1;jud[7774]=1;jud[7777]=1;

  int n,m;
  cin >> n >> m;
  for(int i=1;i<=n;i++){
    cin >> a[i];
    add(i,jud[a[i]]);
  }

  for(int i=0;i<m;i++){
    string s;
    cin >> s;
    if(s[0]=='c'){
      int l,r;
      cin >> l >> r;
      cout << sum(r)-sum(l-1) << '\n';
    }
    else{
      int l,r,d;
      cin >> l >> r >> d;
      for(int i=l;i<=r;i++){
        int del=-jud[a[i]];
        a[i]+=d;
        del+=jud[a[i]];

        if(del!=0){add(i,del);}
      }
    }
  }
  return 0;
}