#include <iostream>
long long n,i,f[222];
int main() {
  std::cin>>n;
  for (f[0]=f[1]=i=1; f[i]<=n; i++) f[i+1]=f[i]+f[i-1];
  std::cout<<i-2<<'\n';
  return 0;
}