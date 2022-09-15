#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  for(int i=0;i<N;i++){
    int64_t m,d,w;
    cin>>m>>d>>w;
    w/=gcd(d-1,w);
    int64_t A=min(m,d),Z=0;
    int64_t B=(A-1)/w;
    Z+=A*B;
    Z-=w*B*(B+1)/2;
    cout<<Z<<endl;
  }
}