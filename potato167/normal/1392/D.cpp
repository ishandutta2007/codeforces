#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  for(int l=0;l<N;l++){
    int M;
    string S;
    cin>>M>>S;
    vector<int> p;
    int A=1;
    for(int i=1;i<M;i++){
      if(S[i-1]==S[i]){
        A++;
      }
      else{
        p.push_back(A);
        A=1;
      }
    }
    p.push_back(A);
    int X=p.size();
    if(X==1){
      cout<<(M+2)/3<<endl;
    }
    else{
      if(S[0]==S[M-1]){
        p[0]+=p[X-1];
        p[X-1]=0;
      }
      int Z=0;
      for(int i=0;i<X;i++){
        Z+=p[i]/3;
      }
      cout<<Z<<endl;
    }
  }
}