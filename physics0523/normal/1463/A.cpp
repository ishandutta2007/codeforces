#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long a,b,c;
    cin >> a >> b >> c;
    long long s=(a+b+c);
    if((s%9)!=0){cout << "No\n";continue;}
    if(a<(s/9) || b<(s/9) || c<(s/9)){cout << "No\n";continue;}
    cout << "Yes\n";
  }
}