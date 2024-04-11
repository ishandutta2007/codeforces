#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long double a,d;
  cin >> a >> d;
  int n;
  cin >> n;
  for(int i=1;i<=n;i++){
    long double pt=d*((long double)i);
    long double md=fmodl(pt,a);
    long long typ=(((pt-md)/a)+0.5);
    typ%=4;
    if(typ==0){
      cout << md << " 0.0\n";
    }
    if(typ==1){
      cout << a << ' ' << md << '\n';
    }
    if(typ==2){
      cout << a-md << ' ' << a << '\n';
    }
    if(typ==3){
      cout << "0.0 " << a-md << '\n';
    }
  }
  return 0;
}