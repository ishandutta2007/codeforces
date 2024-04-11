#include <bits/stdc++.h>
using namespace std;

int64_t I=1167167167167167167;

int main() {
  int N;
  cin>>N;
  vector<int64_t> p(N);
  for(int i=0;i<N;i++){
    cin>>p[i];
  }
  int64_t Z=1167167167167167167,A=0;
  sort(p.begin(),p.end());
  for(int64_t i=1;i<100000;i++){
    vector<int64_t> q(N);
    q[0]=1;
    for(int j=1;j<N;j++){
      if(q[j-1]>I/i){
        A=1;
        break;
      }
      q[j]=q[j-1]*i;
    }
    if(A){
        break;
    }
    int64_t C=0;
    for(int i=0;i<N;i++){
      C+=abs(q[i]-p[i]);
    }
    Z=min(Z,C);
  }
  cout<<Z<<endl;
}