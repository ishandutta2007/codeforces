#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long a,b;
    cin >> a >> b;
    if(a==b){cout << "0 0\n";}
    else{
      long long d=abs(a-b);
      cout << d << ' ' << min((d-(a%d))%d,a%d) << '\n';
    }
  }
  return 0;
}