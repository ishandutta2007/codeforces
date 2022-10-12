#include<bits/stdc++.h>

using namespace std;

long long llceil(long long a,long long b){if(a%b==0){return a/b;}return (a/b)+1;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,k;
  cin >> n >> k;
  cout << llceil(2ll*n,k)+llceil(5ll*n,k)+llceil(8ll*n,k) << '\n';
  return 0;
}