#include <bits/stdc++.h>
using namespace std;int main(){int t;cin>>t;while(t--){long long n,k;cin>>n>>k;k*=(n+k-1)/k;cout<<(k+n-1)/n<<'\n';}}