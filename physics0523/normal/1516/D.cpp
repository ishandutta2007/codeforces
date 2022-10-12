#include<bits/stdc++.h>

using namespace std;

vector<int> decomp(int x){
  vector<int> res;
  for(int i=2;i*i<=x;i++){
    if(x%i==0){res.push_back(i);}
    while(x%i==0){x/=i;}
  }
  if(x!=1){res.push_back(x);}
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,q;
  cin >> n >> q;
  vector<int> a(n+1);
  int link[22][100005];
  for(int i=1;i<=n;i++){cin >> a[i];}
  link[0][n+1]=n+1;

  vector<int> pc(100005,0);
  long long st=1,na=1,cnt=0;
  while(st<=n){
    if(na==n+2){link[0][st]=na-1;st++;}
    else if(cnt==0){
      if(na==n+1){na++;continue;}
      vector<int> cp=decomp(a[na]);
      na++;
      for(auto &nx : cp){
        if(pc[nx]==1){cnt++;}
        pc[nx]++;
      }
    }
    else{
      link[0][st]=na-1;
      vector<int> cp=decomp(a[st]);
      st++;
      for(auto &nx : cp){
        pc[nx]--;
        if(pc[nx]==1){cnt--;}
      }
    }
  }

  for(int i=1;i<22;i++){
    link[i][n+1]=n+1;
    for(int j=1;j<=n;j++){link[i][j]=link[i-1][link[i-1][j]];}
  }

  while(q>0){
    q--;
    int l,r,res=0;
    cin >> l >> r;
    for(int i=21;i>=0;i--){
      if(link[i][l]<=r){
        l=link[i][l];
        res+=(1<<i);
      }
    }
    cout << res+1 << '\n';
  }
  return 0;
}