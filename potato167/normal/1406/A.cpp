#include <bits/stdc++.h>
using namespace std;

int main() {
  int L;
  cin>>L;
  for(int l=0;l<L;l++){
    int N;
    cin>>N;
    vector<int> p(101);
    for(int i=0;i<N;i++){
      int a;
      cin>>a;
      p[a]++;
    }
    int Z=0,A=0;
    for(int i=0;i<=100;i++){
      int D=(max(0,2-A-p[i]));
      Z+=i*D;
      A+=D;
      if(A==2){
        break;
      }
    }
    cout<<Z<<endl;
  }
}