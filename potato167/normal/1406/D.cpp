#include <bits/stdc++.h>
using namespace std;

int64_t zero=0;

int main() {
  int64_t N,Z=0;
  cin>>N;
  vector<int64_t> p(N);
  for(int i=0;i<N;i++){
    cin>>p[i];
  }
  vector<int64_t> q(N-1);
  for(int i=0;i<N-1;i++){
    q[i]=p[i+1]-p[i];
    if(q[i]>0){
      Z+=q[i];
    }
  }
  if(Z+1+p[0]>0){
    cout<<(Z+1+p[0])/2<<endl;
  }
  else{
    cout<<((abs(Z+p[0]))/2)*-1<<endl;
  }
  int Q;
  cin>>Q;
  for(int i=0;i<Q;i++){
    int a,b,c;
    cin>>a>>b>>c;
    a-=2,b--;
    if(a!=-1){
      int64_t D=q[a]+c;
      Z-=max(zero,q[a]);
      Z+=max(zero,D);
      q[a]=D;
    }
    else{
      p[0]+=c;
    }
    if(b!=N-1){
      int64_t D=q[b]-c;
      Z-=max(zero,q[b]);
      Z+=max(zero,D);
      q[b]=D;
    }
    if(Z+1+p[0]>0){
      cout<<(Z+1+p[0])/2<<endl;
    }
    else{
      cout<<((abs(Z+p[0]))/2)*-1<<endl;
    }
  }
}