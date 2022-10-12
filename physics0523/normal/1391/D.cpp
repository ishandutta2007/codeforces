#include<bits/stdc++.h>
#define inf 1000000007

using namespace std;

int cvrt(string s){
  int l=s.size(),res=0;
  for(int i=0;i<l;i++){
    res*=2;
    if(s[i]=='1'){res++;}
  }
  return res;
}

int dsumb(int x,int b){int r=0;while(x){r+=(x%b);x/=b;}return r;}

int dist(int i,int j){
  return dsumb((i^j),2);
}

bool vld(int i,int j,int d){
  while(d>=2){
    int v=((i&3)^(j&3));
    if(v==0 || v==3){return false;}
    i>>=1;j>>=1;d--;
  }
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin >> n >> m;
  if(n>=4 && m>=4){cout << "-1\n";return 0;}
  if(n==1 || m==1){cout << "0\n";return 0;}
  vector<string> s(n);
  for(int i=0;i<n;i++){cin >> s[i];}
  if(m>=4){
    vector<string> mem(m);
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        mem[j].push_back(s[i][j]);
      }
    }
    s.swap(mem);
    swap(n,m);
  }

  int dg=m;
  vector<int> dp((1<<m),0);
  for(int i=0;i<n;i++){
    vector<int> ndp((1<<m),inf);
    for(int j=0;j<(1<<m);j++){
      int cd=dist(cvrt(s[i]),j);
      for(int k=0;k<(1<<m);k++){
        if(vld(k,j,dg)){ndp[j]=min(ndp[j],dp[k]+cd);}
      }
    }
    dp.swap(ndp);
    //for(int j=0;j<(1<<m);j++){cout << dp[j];}cout << '\n';
  }
  int res=inf;
  for(auto &nx : dp){res=min(nx,res);}
  cout << res << '\n';
  return 0;
}