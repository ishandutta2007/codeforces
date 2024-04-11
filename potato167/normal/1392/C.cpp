#include <bits/stdc++.h>
using namespace std;

int main() {
  int K;
  cin>>K;
  for(int l=0;l<K;l++){
    int N;
    cin>>N;
    vector<int64_t> p(N);
    for(int i=0;i<N;i++){
      cin>>p[i];
    }
    int64_t Z=0,M=p[0];
    for(int i=1;i<N;i++){
      M=max(M,p[i]);
      if(p[i-1]>p[i]){
        Z+=p[i-1]-p[i];
      }
    }
    cout<<Z<<endl;
  }
}