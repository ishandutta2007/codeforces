#include<bits/stdc++.h>

using namespace std;

long long lldsum(long long x){long long r=0;while(x){r+=(x%10);x/=10;}return r;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    long long n;
    cin >> n;
    while(1){
      if(gcd(n,lldsum(n))>1){break;}
      n++;
    }
    cout << n << '\n';
  }
  return 0;
}