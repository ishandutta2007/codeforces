#include<bits/stdc++.h>
#define inf 1072114514
#define sz 1333

using namespace std;

int dp[sz][sz][2][4];

int rep(int sg,int db,int ct,int kd){
  if(sg==0 && db==0 && ct==0){return 0;}
  if(dp[sg][db][ct][kd]!=inf){return dp[sg][db][ct][kd];}
  int res;
  if(kd&1){res=inf;}else{res=-inf;}

  //rev
  if((kd&2)!=0 && sg>0){
    int ss=rep(sg,db,ct,(kd^3));
    if(kd&1){res=min(ss,res);}
    else{res=max(ss,res);}
  }

  //fill sg
  if(sg>0){
    int ss=rep(sg-1,db,ct,((kd|2)^1));
    if(kd&1){res=min(ss+1,res);}
    else{res=max(ss-1,res);}
  }

  //fill db
  if(db>0){
    int ss=rep(sg+1,db-1,ct,((kd|2)^1));
    if(kd&1){res=min(ss+1,res);}
    else{res=max(ss-1,res);}
  }

  //fill ct
  if(ct>0){
    int ss=rep(sg,db,ct-1,((kd|2)^1));
    if(kd&1){res=min(ss+1,res);}
    else{res=max(ss-1,res);}
  }

  dp[sg][db][ct][kd]=res;
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  for(int i=0;i<sz;i++){
    for(int j=0;j<sz;j++){
      for(int k=0;k<2;k++){
        for(int l=0;l<4;l++){
          dp[i][j][k][l]=inf;
        }
      }
    }
  }
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    string s;
    cin >> n >> s;
    int sg=0,db=0,ct=0;
    for(int i=0;i<n;i++){
      int j=n-1-i;
      if(i>j){break;}
      else if(i==j){if(s[i]=='0'){ct++;}}
      else{
        if(s[i]=='0' && s[j]=='0'){db++;}
        else if(s[i]=='0' || s[j]=='0'){sg++;}
      }
    }
    int res=rep(sg,db,ct,2);
    if(res>0){cout << "ALICE\n";}
    else if(res<0){cout << "BOB\n";}
    else{cout << "DRAW\n";}
  }
  return 0;
}