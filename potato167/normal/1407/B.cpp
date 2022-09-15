#include <bits/stdc++.h>
using namespace std;
int main(){
  int Q;
  cin>>Q;
  for(int l=0;l<Q;l++){
    int N;
    cin>>N;
    vector<int> p(N);
    for(int i=0;i<N;i++){
      cin>>p[i];
    }
    sort(p.begin(),p.end());
    vector<int> q(N);
    vector<int> r(N);
    q[0]=p[N-1];
    r[N-1]=1;
    int Z=p[N-1],A;
    for(int i=1;i<N;i++){
      int D=0,K=0;
      for(int j=0;j<N;j++){
        if(r[j]){
          continue;
        }
        A=gcd(Z,p[j]);
        if(D<A){
          D=A;
          K=j;
        }
      }
      q[i]=p[K];
      r[K]=1;
      Z=D;
    }
    for(int i=0;i<N;i++){
      cout<<q[i];
      if(i+1!=N){
        cout<<" ";
      }
    }
    cout<<endl;
  }
}