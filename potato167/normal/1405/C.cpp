#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin>>t;
  for(int l=0;l<t;l++){
    int N,K,Z=1;
    cin>>N>>K;
    string S;
    cin>>S;
    for(int i=K;i<N;i++){
      if(S[i]=='?'&&S[i-K]!='?'){
        S[i]=S[i-K];
      }
      else if(S[i]!='?'&&S[i-K]=='?'){
        S[i-K]=S[i];
      }
      else if(S[i]!='?'&&S[i-K]=='?'){
        continue;
      }
      else if(S[i]!=S[i-K]){
        Z=0;
      }
    }
    for(int i=N-1;i>=K;i--){
      if(S[i]=='?'&&S[i-K]!='?'){
        S[i]=S[i-K];
      }
      else if(S[i]!='?'&&S[i-K]=='?'){
        S[i-K]=S[i];
      }
      else if(S[i]!='?'&&S[i-K]=='?'){
        continue;
      }
      else if(S[i]!=S[i-K]){
        Z=0;
      }
    }
    if(Z){
      int A=0,B=0;
      for(int i=0;i<K;i++){
        if(S[i]=='1'){
          A++;
        }
        if(S[i]=='0'){
          B++;
        }
      }
      if(A*2>K||B*2>K){
        Z=0;
      }
    }
    if(Z){
      cout<<"YES"<<endl;
    }
    else{
      cout<<"NO"<<endl;
    }
  }
}