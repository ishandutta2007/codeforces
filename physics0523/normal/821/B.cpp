#include<bits/stdc++.h>

using namespace std;

long long llsankaku(long long x){return ((1+x)*x)/2;}
long long llceil(long long a,long long b){if(a%b==0){return a/b;}return (a/b)+1;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long m,b,res=0;
  cin >> m >> b;
  for(long long x=0;x<=m*b;x++){
    long long y=b-llceil(x,m);
    res=max(llsankaku(x)*(y+1)+llsankaku(y)*(x+1),res);
  }
  cout << res << '\n';
  return 0;
}