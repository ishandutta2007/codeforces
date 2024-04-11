#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin>>t;
  for(int l=0;l<t;l++){
    int N;
    cin>>N;
    vector<int> p(N);
    for(int i=0;i<N;i++){
      cin>>p[i];
    }
    for(int i=N-1;i>0;i--){
      cout<<p[i]<<" ";
    }
    cout<<p[0]<<endl;
  }
}