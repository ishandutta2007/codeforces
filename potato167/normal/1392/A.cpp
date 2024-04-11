#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  for(int i=0;i<N;i++){
    int M,Z=0,A;
    cin>>M>>A;
    for(int j=1;j<M;j++){
      int a;
      cin>>a;
      if(A!=a){
        Z=1;
      }
    }
    if(Z){
      cout<<"1"<<endl;
    }
    else{
      cout<<M<<endl;
    }
  }
      
}