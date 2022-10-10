#include <iostream>
using namespace std;
int i,j,s;
long long l,r,x,y;
int main() {
  cin>>l>>r;
  for (i=1; i<=60; i++) {
    x=(1LL<<i)-1;
    for (j=0; j<i-1; j++) {
      y=x-(1LL<<j);
      if (y>=l && y<=r) s++;
    }
  }
  cout<<s;
  return 0;
}