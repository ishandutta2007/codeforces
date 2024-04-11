#include<bits/stdc++.h>

using namespace std;

long long llceil(long long a,long long b){if(a%b==0){return a/b;}return (a/b)+1;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,x;
    cin >> n >> x;
    long long mi=0,ma=0;
    for(int i=0;i<n;i++){
      long long v;
      cin >> v;
      mi+=v;
      ma+=llceil(v,x);
    }
    mi=llceil(mi,x);
    cout << mi << ' ' << ma << '\n';
  }
  return 0;
}