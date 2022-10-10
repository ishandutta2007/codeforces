#include <bits/stdc++.h>
using namespace std;
int a,b,c;
long long r;
int main() {
  scanf("%d%d%d",&a,&b,&c);
  r=c*2;
  r+=min(a,b)*2;
  if (a!=b) r++;
  cout<<r;
  return 0;
}