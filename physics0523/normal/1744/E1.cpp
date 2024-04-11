#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long a,b,c,d;
    cin >> a >> b >> c >> d;
    long long res=0;
    bool ok=false;
    for(long long i=a+1;(!ok) && i<=c;i++){
      long long mult=a*b;
      mult/=gcd(a*b,i);
      if((d/mult)!=(b/mult)){
        cout << i << " " << (d/mult)*mult << "\n";
        ok=true;break;
      }
    }
    if(!ok){cout << "-1 -1\n";}
  }
  return 0;
}