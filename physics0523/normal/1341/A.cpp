#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n,a,b,c,d;
    cin >> n >> a >> b >> c >> d;
    a*=n;b*=n;
    if(a+b<c-d || c+d<a-b){cout << "No\n";}
    else{cout << "Yes\n";}
  }
  return 0;
}