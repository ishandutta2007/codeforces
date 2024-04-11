#include<bits/stdc++.h>

using namespace std;

int dp[2][2][128][128]={0};

int solve(int ap,int hand,int even,int odd){
  if(even==0 && odd==0){
    if(ap%2==0){return 1;}
    else{return -1;}
  }
  if(dp[ap][hand][even][odd]!=0){
    return dp[ap][hand][even][odd];
  }

  int cres;
  if(hand==0){
    // alice
    cres=-1;
    if(even>0){
      if(solve(ap,1-hand,even-1,odd)==1){cres=1;}
    }
    if(odd>0){
      if(solve((ap+1)%2,1-hand,even,odd-1)==1){cres=1;}
    }
  }
  else{
    // bob
    cres=1;
    if(even>0){
      if(solve(ap,1-hand,even-1,odd)==-1){cres=-1;}
    }
    if(odd>0){
      if(solve(ap,1-hand,even,odd-1)==-1){cres=-1;}
    }
  }

  dp[ap][hand][even][odd]=cres;
  return cres;
}

void work(){
  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
      for(int k=0;k<128;k++){
        for(int l=0;l<128;l++){
          solve(i,j,k,l);
        }
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  work();

  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    int even=0,odd=0;
    for(int i=0;i<n;i++){
      int v;
      cin >> v;
      if(v%2==0){even++;}
      else{odd++;}
    }
    if(dp[0][0][even][odd]==1){cout << "Alice\n";}
    else{cout << "Bob\n";}
  }
  return 0;
}