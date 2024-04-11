#include <bits/stdc++.h>

using namespace std;

int main(){
  int a,b,c,d;
  char s;
  cin >> a >> s >> b >> c >> s >> d;
  a=a*60+b;
  c=c*60+d;
  if(a>=c)a-=c;
  else a=(1440-(c-a));
  if(a==1440)cout << "00:00";
  else{
    if(a/60<10)cout << 0;
    cout << a/60 << ":";
    if(a%60<10)cout << 0;
    cout << a%60;
  }
  return 0;
}