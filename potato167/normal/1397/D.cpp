#include <bits/stdc++.h>
using namespace std;

int main() {
  int M;
  cin>>M;
  for(int l=0;l<M;l++){
    int N;
    cin>>N;
    vector<int> p(N);
    int A=0,T=0;
    for(int i=0;i<N;i++){
      cin>>p[i];
      A+=p[i];
      T=max(T,p[i]);
    }
    T*=2;
    if(T>A||A%2==1){
      cout<<"T"<<endl;
    }
    else{
      cout<<"HL"<<endl;
    }
  }
}