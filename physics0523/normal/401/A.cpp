#include<bits/stdc++.h>

using namespace std;

long long llceil(long long a,long long b){if(a%b==0){return a/b;}return (a/b)+1;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n,x,sig=0;
  cin >> n >> x;
  for(int i=0;i<n;i++){
    long long v;
    cin >> v;
    sig+=v;
  }
  cout << llceil(abs(sig),x) << '\n';
  return 0;
}