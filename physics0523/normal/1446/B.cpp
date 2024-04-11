#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define inf 1072114514
#define size 5005

using namespace std;

int n,m;
string a,b;
int dp[size][size]={0};
int alink[size][32];
int blink[size][32];

int rep(int p,int q){
  if(p<0 || q<0){return 0;}
  if(dp[p][q]!=-1){return dp[p][q];}
  dp[p][q]=0;
  if(p!=0){dp[p][q]=max(dp[p][q],rep(p-1,q)-1);}
  if(q!=0){dp[p][q]=max(dp[p][q],rep(p,q-1)-1);}
  int sc;
  if(a[p]==b[q]){sc=4;}
  else{sc=0;}
  dp[p][q]=max(sc-2,dp[p][q]);
  for(int i=0;i<26;i++){
    int np=alink[p][i];
    int nq=blink[q][i];
    if(np<0 || nq<0){continue;}
    dp[p][q]=max(rep(np,nq)+sc-(p-np)-(q-nq),dp[p][q]);
  }
  return dp[p][q];
}

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  cin >> n >> m;
  cin >> a >> b;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      dp[i][j]=-1;
    }
  }
  int mem[32];
  for(int i=0;i<26;i++){mem[i]=-1;}
  for(int i=0;i<n;i++){
    for(int j=0;j<26;j++){
      alink[i][j]=mem[j];
    }
    mem[a[i]-'a']=i;
  }
  for(int i=0;i<26;i++){mem[i]=-1;}
  for(int i=0;i<m;i++){
    for(int j=0;j<26;j++){
      blink[i][j]=mem[j];
    }
    mem[b[i]-'a']=i;
  }

  int res=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      res=max(rep(i,j),res);
    }
  }
  cout << res << '\n';
  return 0;
}