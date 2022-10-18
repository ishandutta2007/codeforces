#include<bits/stdc++.h>
using namespace std;
int INF=10000;
int main(){
  int N,M;
  cin>>N>>M;
  string S,T;
  cin>>S>>T;
  vector<int> A(N);
  vector<int> B(M);
  for(int i=0;i<N;i++){
    A[i]=(int)(S[i])-48;
  }
  for(int i=0;i<M;i++){
    B[i]=(int)(T[i])-48;
  }
  B.push_back(2);
  vector<vector<int>> P(M+1,vector<int>(2,0));
  for(int i=0;i<=M;i++){
    for(int j=0;j<2;j++){
      if(i!=M){
        if(j==B[i]){
          P[i][j]=i+1;
          continue;
        }
        for(int k=0;k<=i;k++){
          bool f=true;
          for(int l=0;l<k;l++){
            if(l+1==k){
              if(j!=B[l]){
                f=false;
                break;
              }
            }else{
              if(T[l]!=T[i+l-k+1]){
                f=false;
                break;
              }
            }
          }
          if(f){
            P[i][j]=k;
          }
        }
      }else{
        for(int k=0;k<=i;k++){
          bool f=true;
          for(int l=0;l<k;l++){
            if(l+1==k){
              if(j!=B[l]){
                f=false;
                break;
              }
            }else{
              if(T[l]!=T[M+l-k+1]){
                f=false;
                break;
              }
            }
          }
          if(f){
            P[i][j]=k;
          }
        }
      }
    }
  }
  int K=N-M+2;
  vector<vector<vector<int>>> DP(N+1,vector<vector<int>>(K+1,vector<int>(M+1,INF)));
  DP[0][0][0]=0;
  int x,y;
  for(int i=0;i<N;i++){
    for(int j=0;j<K;j++){
      for(int k=0;k<=M;k++){
        for(int l=0;l<2;l++){
          x=P[k][l];
          y=j;
          if(x==M){
            y++;
          }
          DP[i+1][y][x]=min(DP[i+1][y][x],DP[i][j][k]+(A[i]^l));
        }
      }
    }
  }
  vector<int> ANS(K,INF);
  for(int i=0;i<K;i++){
    for(int j=0;j<=M;j++){
      ANS[i]=min(ANS[i],DP[N][i][j]);
    }
    if(i){
      cout<<" ";
    }
    if(ANS[i]==INF){
      ANS[i]=-1;
    }
    cout<<ANS[i];
  }
  cout<<endl;
}