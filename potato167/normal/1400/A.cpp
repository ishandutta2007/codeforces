#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  for(int l=0;l<N;l++){
    int M;
    cin>>M;
    string S;
    cin>>S;
    string T="";
    int K=S.size();
    for(int i=0;i<K-M+1;i++){
      T+=S[i*2];
    }
    while(T.size()<M){
      T+="0";
    }
    cout<<T<<endl;
  }
}