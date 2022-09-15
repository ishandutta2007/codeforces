#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  for(int l=0;l<N;l++){
    int a0,a1,a2,b0,b1,b2;
    cin>>a0>>a1>>a2>>b0>>b1>>b2;
    int A=min(a2,b1);
    int B=max(0,b2-(a0+a2-A));
    A-=B;
    A*=2;
    cout<<A<<endl;
  }
}