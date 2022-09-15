#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin>>t;
  for(int l=0;l<t;l++){
    int N;
    cin>>N;
    int64_t Z=0,A=0;
    for(int i=0;i<N;i++){
      int64_t a;
      cin>>a;
      A+=a;
      Z=min(Z,A);
    }
    Z*=-1;
    cout<<Z<<endl;
  }
}