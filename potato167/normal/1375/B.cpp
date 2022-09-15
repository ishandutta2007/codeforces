#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  for(int l=0;l<N;l++){
    int H,W,Z=1;
    cin>>H>>W;
    vector<vector<int>> p(H+2,vector<int>(W+2));
    for(int i=1;i<=H;i++){
      for(int j=1;j<=W;j++){
        cin>>p[i][j];
      }
    }
    for(int i=1;i<=H;i++){
      for(int j=1;j<=W;j++){
        int A=2;
        if(i!=1&&i!=H){
          A++;
        }
        if(j!=1&&j!=W){
          A++;
        }
        if(A<p[i][j]){
          Z=0;
          break;
        }
      }
    }
    if(Z==0){
      cout<<"NO"<<endl;
    }
    else{
      cout<<"YES"<<endl;
      for(int i=1;i<=H;i++){
      for(int j=1;j<=W;j++){
        int A=2;
        if(i!=1&&i!=H){
          A++;
        }
        if(j!=1&&j!=W){
          A++;
        }
        cout<<A;
        if(j==W){
          cout<<endl;
        }
        else{
cout<<" ";
        }
      }
    }
    }
  }
    
}