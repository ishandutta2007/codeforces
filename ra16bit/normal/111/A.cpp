#include <iostream>
using namespace std;
int n,i;
long long x,y,z;
int main() {
  cin>>n>>x>>y;
  if (n>y) { cout<<"-1\n"; return 0; }
  z=n-1+(y-n+1)*(y-n+1);
  if (z>=x) {
    cout<<y-n+1<<'\n';
    for (i=1; i<n; i++) cout<<"1\n";
  } else cout<<"-1\n";
  return 0;
}