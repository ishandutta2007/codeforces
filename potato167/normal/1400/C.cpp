#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  for(int l=0;l<N;l++){
    string S;
    int x;
    cin>>S;
    cin>>x;
    int L=S.size(),Z=0;
    vector<int> zero(L);
    vector<int> ichi(L);
    for(int i=0;i<L;i++){
      if(i-x>=0&&i+x<L){
        if(S[i]=='0'){
          zero[i+x]=1;
          zero[i-x]=1;
        }
      }
      else if(i-x>=0){
        if(S[i]=='0'){
          zero[i-x]=1;
        }
        else{
          ichi[i-x]=1;
        }
      }
      else if(i+x<L){
        if(S[i]=='0'){
          zero[i+x]=1;
        }
        else{
          ichi[i+x]=1;
        }
      }
      else if(S[i]=='1'){
        Z++;
      }
    }
    string T="";
    for(int i=0;i<L;i++){
      if(zero[i]&&ichi[i]){
        Z++;
      }
      else if(zero[i]){
        T+="0";
      }
      else{
        T+="1";
      }
    }
    if(Z==0){
      for(int i=0;i<L;i++){
      if(S[i]=='0'){
        continue;
      }
      if(i-x>=0&&i+x<L){
        if(T[i-x]=='0'&&T[i+x]=='0'){
          Z++;
        }
      }
      else if(i-x>=0){
        if(T[i-x]=='0'){
          Z++;
        }
      }
      else if(i+x<L){
        if(T[i+x]=='0'){
          Z++;
        }
      }
    }
    }
    if(Z!=0){
      cout<<"-1"<<endl;
    }
    else{
      cout<<T<<endl;
    }
  }
}