#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  for(int l=0;l<N;l++){
    int M;
    int64_t K;
    cin>>M>>K;
    K%=2;
    int Z=-1671671671;
    int A=Z;
    vector<int> p(M);
    for(int i=0;i<M;i++){
      cin>>p[i];
      Z=max(Z,p[i]);
    }
    for(int i=0;i<M;i++){
      p[i]=Z-p[i];
      A=max(A,p[i]);
    }
    if(K==1){
      for(int i=0;i<M;i++){
        cout<<p[i];
        if(i==M-1){
          cout<<endl;
        }
        else{
          cout<<" ";
        }
      }
    }
    else{
      for(int i=0;i<M;i++){
        cout<<A-p[i];
        if(i==M-1){
          cout<<endl;
        }
        else{
          cout<<" ";
        }
      }
    }
    
  }
      
}