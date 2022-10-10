#include <iostream>
using namespace std;
int n,i,j;
long long l,r,res;
int main() {
  cin>>n;
  while (n--) {
    cin>>l>>r;
    res=0; r++;
    for (i=62; i>=0; i--) {
      if (((l>>i)&1)!=((r>>i)&1)) {
        res+=(1LL<<i)-1;
        break;
      }
      res+=(l&(1LL<<i));
    }
    cout<<res<<'\n';
  }
  return 0;
}