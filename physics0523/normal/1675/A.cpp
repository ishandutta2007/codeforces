#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    if((x+y)>a+b+c){cout << "NO\n";continue;}
    if((x)>a+c){cout << "NO\n";continue;}
    if((y)>b+c){cout << "NO\n";continue;}
    cout << "YES\n";
  }
  return 0;
}