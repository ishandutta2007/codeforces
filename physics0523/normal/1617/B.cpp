#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    bool ex=false;
    for(int c=1;c<=n;c++){
      for(int a=1;a+c<=n;a++){
        if(a==c){continue;}
        int b=(n-(a+c));
        if(b<=0){continue;}
        if(b==a || b==c){continue;}
        if(gcd(a,b)==c){
          cout << a << ' ' << b << ' ' << c << '\n';
          ex=true;
          break;
        }
        if(ex){break;}
      }
      if(ex){break;}
    }
  }
  return 0;
}